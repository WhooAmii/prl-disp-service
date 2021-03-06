////////////////////////////////////////////////////////////////////////////////
///
/// Copyright (c) 2005-2017, Parallels International GmbH
/// Copyright (c) 2017-2019 Virtuozzo International GmbH, All rights reserved.
///
/// This file is part of Virtuozzo Core. Virtuozzo Core is free
/// software; you can redistribute it and/or modify it under the terms
/// of the GNU General Public License as published by the Free Software
/// Foundation; either version 2 of the License, or (at your option) any
/// later version.
/// 
/// This program is distributed in the hope that it will be useful,
/// but WITHOUT ANY WARRANTY; without even the implied warranty of
/// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
/// GNU General Public License for more details.
/// 
/// You should have received a copy of the GNU General Public License
/// along with this program; if not, write to the Free Software
/// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
/// 02110-1301, USA.
///
/// Our contact details: Virtuozzo International GmbH, Vordergasse 59, 8200
/// Schaffhausen, Switzerland.
///
/// @file
///  Task_DeleteVm.cpp
///
/// @brief
///  Definition of the class CDspTaskHelper
///
/// @brief
///  This class implements long running tasks helper class
///
/// @author sergeyt
///  SergeyT@
///
////////////////////////////////////////////////////////////////////////////////

#include <prlcommon/ProtoSerializer/CProtoSerializer.h>
#include "CDspClientManager.h"
#include "CDspBugPatcherLogic.h"
#include "CDspTemplateStorage.h"
#include "Task_DeleteVm.h"
#include "Task_DeleteVm_p.h"
#include "Task_CommonHeaders.h"
#include <prlcommon/Logging/Logging.h>
#include <prlcommon/PrlCommonUtilsBase/SysError.h>
#include <prlcommon/Std/PrlAssert.h>
#include <prlcommon/HostUtils/HostUtils.h>
#include "Libraries/StatesUtils/StatesHelper.h"
#include "CDspBackupDevice.h"
#include "CDspVm_p.h"
#include <boost/foreach.hpp>
#include <boost/lambda/bind.hpp>
#include <boost/lambda/lambda.hpp>

using namespace Virtuozzo;

// By adding this interface we enable allocations tracing in the module
#include "Interfaces/Debug.h"

Task_DeleteVm::Task_DeleteVm (
	SmartPtr<CDspClient>& client,
	const SmartPtr<IOPackage>& p,
	const QString& vm_config):

	CDspTaskHelper(client, p),
	m_flags(),
	m_flgVmWasDeletedFromSystemTables(),
	m_flgExclusiveOperationWasRegistred(),
	m_flgLockRegistred(), m_registry(),
	m_script(new Instrument::Command::Delete::Script())
{
	m_pVmConfig = SmartPtr<CVmConfiguration>(new CVmConfiguration( vm_config ));

	//////////////////////////////////////////////////////////////////////////
	setTaskParameters( m_pVmConfig->getVmIdentification()->getVmUuid() );
}

void Task_DeleteVm::setTaskParameters( const QString& vm_uuid )
{
	CDspLockedPointer<CVmEvent> pParams = getTaskParameters();

	pParams->addEventParameter(
		new CVmEventParameter( PVE::String, vm_uuid, EVT_PARAM_DISP_TASK_VM_DELETE_VM_UUID ) );
}

bool Task_DeleteVm::doUnregisterOnly()
{
    return m_flags & PVD_UNREGISTER_ONLY;
}

QString Task_DeleteVm::getVmUuid()
{
    return m_pVmConfig ? m_pVmConfig->getVmIdentification()->getVmUuid() : QString();
}

PRL_RESULT Task_DeleteVm::prepareTask()
{
	CDspTaskFailure f(*this);
	PRL_RESULT ret = PRL_ERR_SUCCESS;

	try
	{
		/**
		* check parameters
		*/
		if( !IS_OPERATION_SUCCEEDED( m_pVmConfig->m_uiRcInit ) )
		{
			// send error to user: can't parse VM config
			throw f(PRL_ERR_CANT_PARSE_VM_CONFIG);
		}

		QString vm_name = m_pVmConfig->getVmIdentification()->getVmName();
		QString vm_uuid = getVmUuid();

		m_vmDirectoryUuid = CDspVmDirHelper::getVmDirUuidByVmUuid(vm_uuid, getClient());
		if (m_vmDirectoryUuid.isEmpty())
			throw PRL_ERR_VM_UUID_NOT_FOUND;

		// TODO fix lock managment and remove this state check
		if (!m_pVmConfig->getVmSettings()->getVmCommonOptions()->isTemplate())
		{
			VIRTUAL_MACHINE_STATE s;
			Libvirt::Result r = Libvirt::Kit.vms().at(vm_uuid).getState().getValue(s);
			if (r.isSucceed() && s != VMS_STOPPED && s != VMS_SUSPENDED)
				return f(PRL_ERR_DISP_VM_IS_NOT_STOPPED, getVmUuid());

			if (NULL == m_registry)
			{
				m_script->with(s, Registry::Access
					(vm_uuid, QWeakPointer<Registry::Vm>()));
			}
			else
				m_script->with(s, m_registry->find(vm_uuid));
		}
		if (!(m_flags & PVD_SKIP_VM_OPERATION_LOCK))
		{
			ret = CDspService::instance()->getVmDirHelper().registerExclusiveVmOperation(
				vm_uuid, m_vmDirectoryUuid,
				( PVE::IDispatcherCommands ) getRequestPackage()->header.type,
				getClient() );
			if( PRL_FAILED( ret ) )
				throw ret;
			m_flgExclusiveOperationWasRegistred = true;
		}
		/**
		 * find VM in global VM hash
		 */
		{
			CDspLockedPointer<CVmDirectoryItem> pDirectoryItem =
				CDspService::instance()->getVmDirHelper().getVmDirectoryItemByUuid( m_vmDirectoryUuid, vm_uuid);

			if ( ! pDirectoryItem )
			{
				// send error to user: VM with given UUID is not found
				throw f(PRL_ERR_VM_UUID_NOT_FOUND);
			}

			m_sVmHomePath = pDirectoryItem->getVmHome();

			ret = checkUserAccess( pDirectoryItem );
			if (PRL_FAILED( ret ))
				throw ret;

		} // end bracket for CDspLockedPointer<CVmDirectoryItem>


		//LOCK vm directory before deleting and locking.
		CDspLockedPointer< CVmDirectory >
			pLockedVmDir = CDspService::instance()->getVmDirManager()
				.getVmDirectory(m_vmDirectoryUuid);


		/**
		 * check if such VM is not already registered in user's prepare_VM directory
		 */
		m_pVmInfo.reset(new CVmDirectory::TemporaryCatalogueItem(vm_uuid, m_sVmHomePath, vm_name));
		PRL_ASSERT(!m_pVmInfo.isNull());

		m_flgLockRegistred=false;

		PRL_RESULT lockResult = CDspService::instance()->getVmDirManager()
			.lockExistingExclusiveVmParameters(m_vmDirectoryUuid, m_pVmInfo.data());

		if (!PRL_SUCCEEDED(lockResult))
		{
			throw f.setToken(vm_uuid).setToken(m_pVmInfo->vmXmlPath)
				.setToken(vm_name)(lockResult);
		}

		m_flgLockRegistred=true;

		//////////////////////////////////////////////////////////////////////////
		// remove VM from VM Directory
		//////////////////////////////////////////////////////////////////////////
		ret = CDspService::instance()->getVmDirHelper().deleteVmDirectoryItem(
				m_vmDirectoryUuid, vm_uuid);
		if ( ! PRL_SUCCEEDED( ret ) )
		{
			WRITE_TRACE(DBG_FATAL, ">>> Can't delete vm from VmDirectory by error %#x, %s",
				ret, PRL_RESULT_TO_STRING( ret) );
			throw ret;
		}
		if (!(m_flags & PVD_SKIP_HA_CLUSTER))
			CDspService::instance()->getHaClusterHelper()->
					removeClusterResource(vm_name);

		ret = PRL_ERR_SUCCESS;
		m_flgVmWasDeletedFromSystemTables=true;
	}
	catch (PRL_RESULT code)
	{
		ret = code;
		WRITE_TRACE(DBG_FATAL, "Error occurred while deleting VM configuration with code [%#x][%s]",
			code, PRL_RESULT_TO_STRING( code ) );
	}
	getLastError()->setEventCode( ret );

	return ret;
}

void Task_DeleteVm::finalizeTask()
{
	QString sVmUuid = m_pVmConfig
		? m_pVmConfig->getVmIdentification()->getVmUuid()
		: "";

	if (PRL_SUCCEEDED(getLastErrorCode()))
		CDspBugPatcherLogic::cleanVmPatchMarks(m_vmDirectoryUuid, sVmUuid);

	if( doUnregisterOnly() && !(m_flags & PVD_NOT_MODIFY_VM_CONFIG) && PRL_SUCCEEDED(getLastErrorCode()) )
	{
		CDspVmDirManager::VmDirItemsHash
			sharedVmHash = CDspService::instance()->getVmDirManager()
				.findVmDirItemsInCatalogue( sVmUuid ,m_sVmHomePath );

		QString server_id(m_pVmConfig->getVmIdentification()->getServerUuid());
		QString local_id(CDspService::instance()->getDispConfigGuard().getDispConfig()->getVmServerIdentification()->getServerUuid());
		if(Uuid(server_id) == Uuid(local_id) && sharedVmHash.isEmpty() )
		{
			m_pVmConfig->getVmIdentification()->setServerUuid();

			// fix #121634, #121636 - Skip Copy/Move message when VM already registered on same server
			m_pVmConfig->getVmIdentification()->setLastServerUuid(local_id);
		}

		// if vm is in invalid state do not save it
		PRL_RESULT validRc = (PRL_RESULT)m_pVmConfig->getValidRc();
		if ( 	validRc != PRL_ERR_PARSE_VM_CONFIG
			&& validRc != PRL_ERR_VM_CONFIG_DOESNT_EXIST
			&& validRc != PRL_ERR_ACCESS_TO_VM_DENIED // #427453
		)
		{
			m_pVmConfig->setValidRc( PRL_ERR_SUCCESS );
			CDspService::instance()->getVmConfigManager().saveConfig(m_pVmConfig,
				m_sVmHomePath,
				getClient(),
				true,
				true);
		}
	}

	if( PRL_SUCCEEDED(getLastErrorCode()) )
	{
		CDspService::instance()->getVmConfigManager().getHardDiskConfigCache().remove( m_pVmConfig );
		CDspService::instance()->getVmConfigManager().removeFromCache( m_pVmInfo->vmXmlPath );
	}

	if( m_flgExclusiveOperationWasRegistred )
	{
		CDspService::instance()->getVmDirHelper().unregisterExclusiveVmOperation(
			m_pVmConfig->getVmIdentification()->getVmUuid(),
			m_vmDirectoryUuid,
			( PVE::IDispatcherCommands ) getRequestPackage()->header.type,
			getClient() );
	}

	// delete temporary registration
	if (!m_pVmInfo.isNull() && m_flgLockRegistred)
	{
		CDspService::instance()->getVmDirManager()
			.unlockExclusiveVmParameters(m_vmDirectoryUuid, m_pVmInfo.data());
	}

	postVmDeletedEvent();

	// send response
	if ( PRL_FAILED( getLastErrorCode() ) )
		getClient()->sendResponseError( getLastError(), getRequestPackage() );
	else
		getClient()->sendSimpleResponse( getRequestPackage(), getLastErrorCode() );
}

PRL_RESULT Task_DeleteVm::run_body()
{
	namespace ic = Instrument::Chain;

	ic::Delete::Request x(m_pVmConfig, m_strListToDelete);
	if (doUnregisterOnly())
		setLastErrorCode(ic::Unregister(*m_script)(x));
	else
	{
		namespace dc = ic::Delete;
		m_script->with(Instrument::Command::Delete::Guise(getClient()->getAuthHelper()))
			.with(Instrument::Command::Delete::Content(x.getHome(), *this), m_strListToDelete);
		setLastErrorCode(dc::Template::Shared(getClient()->getAuthHelper(),
			dc::Template::Regular(*m_script,
			dc::Vm(*m_script)))(x));
	}
	if (PRL_FAILED(getLastErrorCode()))
	{
		WRITE_TRACE(DBG_FATAL, "Error occurred while deleting VM configuration with code [%#x][%s]",
			getLastErrorCode(), PRL_RESULT_TO_STRING(getLastErrorCode()));
	}
	return getLastErrorCode();

}

/**
* check if user is authorized to access this VM
*/
PRL_RESULT Task_DeleteVm::checkUserAccess( CDspLockedPointer<CVmDirectoryItem> pDirectoryItem )
{
	if ( ! doUnregisterOnly() )
	{
		CDspAccessManager::VmAccessRights
			permissionToVm = CDspService::instance()->getAccessManager()
			.getAccessRightsToVm( getClient(), pDirectoryItem.getPtr() );

		if( ! permissionToVm.canWrite() )
		{
			PRL_RESULT err = permissionToVm.isExists()
				? PRL_ERR_ACCESS_TO_VM_DENIED
				: PRL_ERR_VM_CONFIG_DOESNT_EXIST;

			if (err != PRL_ERR_VM_CONFIG_DOESNT_EXIST)
			{

				// send error to user: user is not authorized to access this VM
				WRITE_TRACE(DBG_FATAL, ">>> User hasn't rights to  access this VM %#x, %s"
					, err, PRL_RESULT_TO_STRING( err ) );
				CDspTaskFailure f(*this);
				if (!pDirectoryItem.isValid())
					return f(err);

				return f.setCode(err)
					(pDirectoryItem->getVmName(), pDirectoryItem->getVmHome());
			}
		}
	} // if ( ! doUnregisterOnly() )

	return PRL_ERR_SUCCESS;
}

/**
* Notify all users that VM was removed
*/
void Task_DeleteVm::postVmDeletedEvent()
{
	if (m_flgVmWasDeletedFromSystemTables ) //&& sharedVmHash.isEmpty() )
	{
		DspVm::vdh().sendVmEventToAll(
			MakeVmIdent(m_pVmConfig->getVmIdentification()->getVmUuid(), m_vmDirectoryUuid),
			(doUnregisterOnly()) ? PET_DSP_EVT_VM_UNREGISTERED : PET_DSP_EVT_VM_DELETED,
			 getRequestPackage());
	}
}

namespace Instrument
{
namespace Command
{
namespace Delete
{
///////////////////////////////////////////////////////////////////////////////
// struct Libvirt

PRL_RESULT Libvirt::operator()()
{
#ifdef _LIBVIRT_
	::Libvirt::Result r(::Libvirt::Kit.vms().at(m_uid)
			.getState().undefine());
	if (r.isFailed())
		return r.error().code();
#endif // _LIBVIRT_

	return PRL_ERR_SUCCESS;
}

///////////////////////////////////////////////////////////////////////////////
// struct Guise

PRL_RESULT Guise::enable()
{
	if (m_auth->Impersonate())
		return PRL_ERR_SUCCESS;

	return PRL_ERR_IMPERSONATE_FAILED;
}

PRL_RESULT Guise::disable()
{
	if (!m_auth->RevertToSelf())
	{
		WRITE_TRACE(DBG_FATAL, "error: %s",
			PRL_RESULT_TO_STRING(PRL_ERR_REVERT_IMPERSONATE_FAILED));
	}

	return PRL_ERR_SUCCESS;
}

///////////////////////////////////////////////////////////////////////////////
// struct Backup

PRL_RESULT Backup::disable()
{
	::Backup::Device::Service(m_vm).setVmHome(m_home).disable();
	return PRL_ERR_SUCCESS;
}

PRL_RESULT Backup::teardown()
{
	::Backup::Device::Service(m_vm).setVmHome(m_home).teardown();
	return PRL_ERR_SUCCESS;
}

///////////////////////////////////////////////////////////////////////////////
// struct Content

PRL_RESULT Content::operator()()
{
	// for server mode delete all files from vm directory #270686
	// common logic for console clients such as prlctl for all modes #436939
	PRL_ASSERT(QFileInfo(m_home).isDir());
	if (CFileHelper::ClearAndDeleteDir(m_home))
		return PRL_ERR_SUCCESS;

	return CDspTaskFailure(*m_task)(PRL_ERR_NOT_ALL_FILES_WAS_DELETED);
}

PRL_RESULT Content::operator()(const QStringList& list_)
{
	QStringList b;
	boost::function<void ()> r;
	foreach (const QString& i, list_)
	{
		// skip not existing files
		if (!CFileHelper::FileExists(i, &m_task->getClient()->getAuthHelper()))
			continue;

		QFileInfo x(i);
		if (x.isFile() && !QFile::remove(i))
			b << i;
		else if (x.isDir())
		{
			if (m_home == i)// vm dir must be deleted at the end
				r = boost::bind(&QDir::rmdir, QDir(), m_home);

			// try to delete incoming directory if it internal directory of vm dir
			// delete only child directory to prevent damage
			// #431558 compare paths by spec way to prevent errors with symlinks, unexisting files, ...
			else if (CFileHelper::IsPathsEqual(x.dir().path(), m_home) &&
				!CFileHelper::ClearAndDeleteDir(i))
				b << i;
		}
	}
	if (!r.empty())
		r();

	if (b.isEmpty())
		return PRL_ERR_SUCCESS;

	CDspTaskFailure f(*m_task);
	WRITE_TRACE(DBG_FATAL, ">>> Not all files can be delete. !removeVmResources( pVmConfig )");
	foreach (const QString& i, b)
	{
		WRITE_TRACE(DBG_FATAL, "file wasn't delete. path = [%s]", qPrintable(i));
		f.setToken(i);
	}

	return f(PRL_ERR_NOT_ALL_FILES_WAS_DELETED);
}

///////////////////////////////////////////////////////////////////////////////
// struct Builder

void Builder::addGuise(const Guise& guise_)
{
	result_type b;
	b.addItem(boost::bind(&Guise::enable, guise_),
		boost::bind(reinterpret_cast<void (Guise::*)()>
			(&Guise::disable), guise_));
	b.addItem(m_result);
	b.addItem(boost::bind(&Guise::disable, guise_));
	m_result = b;
}

void Builder::addLibvirt(origin_type origin_, const access_type& access_)
{
	result_type b;
	if (VMS_UNKNOWN != origin_)
	{
		typedef Registry::Reactor conductor_type;
		namespace bl = boost::lambda;

		conductor_type c(access_.getReactor());
		boost::function<void (origin_type)> F(boost::bind(&conductor_type::proceed, c, _1));
		result_type::redo_type f = (bl::bind(F, VMS_DELETING_STATE), PRL_ERR_SUCCESS);
		b.addItem(f, boost::bind(&conductor_type::proceed, c, origin_));
	}
	b.addItem(Command::Delete::Libvirt(access_.getUuid()));
	b.addItem(m_result);
	m_result = b;
}

///////////////////////////////////////////////////////////////////////////////
// struct Script

Script& Script::with(const Guise& guise_)
{
	m_batch[2] = boost::bind(&Builder::addGuise, _1, guise_);
	return *this;
}

Script& Script::withDisable(const Backup& backup_)
{
	batch_type::redo_type i(boost::bind(&Backup::disable, backup_));
	m_batch[0] = boost::bind(&Builder::addItem, _1, i);
	return *this;
}

Script& Script::withTeardown(const Backup& backup_)
{
	batch_type::redo_type i(boost::bind(&Backup::teardown, backup_));
	m_batch[0] = boost::bind(&Builder::addItem, _1, i);
	return *this;
}

Script& Script::with(const Content& command_, const QStringList& filter_)
{
	result_type::redo_type x;
	if (filter_.isEmpty())
		x = command_;
	else
		x = boost::bind(command_, filter_);

	m_batch[1] = boost::bind(&Builder::addItem, _1, x);
	return *this;
}

Script& Script::with(Builder::origin_type origin_, const Builder::access_type& access_)
{
	m_batch[3] = boost::bind(&Builder::addLibvirt, _1, origin_, access_);
	return *this;
}

Script::result_type Script::operator()() const
{
	Builder x;
	BOOST_FOREACH(const chain_type& c, m_batch)
	{
		if (!c.empty())
			c(boost::ref(x));
	}

	return x.getResult();
}

} // namespace Delete
} // namespace Command

namespace Chain
{
namespace Delete
{
///////////////////////////////////////////////////////////////////////////////
// struct Request

Request::Request(const vm_type& vm_, const QStringList& itemList_):
	m_vm(vm_), m_itemList(itemList_)
{
	if (m_vm.isValid())
	{
		m_home = CFileHelper::GetFileRoot
			(m_vm->getVmIdentification()->getHomePath());
	}
}

bool Request::isTemplate() const
{
	return m_vm.isValid() &&
		m_vm->getVmSettings()->getVmCommonOptions()->isTemplate();
}

namespace Template
{
///////////////////////////////////////////////////////////////////////////////
// struct Shared

Shared::result_type Shared::operator()(const request_type& request_)
{
	if (!request_.isTemplate())
		return base_type::operator()(request_);

	::Template::Storage::Dao::pointer_type p;
	::Template::Storage::Dao d(*m_auth);
	PRL_RESULT e = d.findForEntry(request_.getHome(), p);
	if (PRL_FAILED(e))
		return base_type::operator()(request_);

	e = p->unlink(QFileInfo(request_.getHome()).fileName());
	if (PRL_FAILED(e))
		return e;

	return p->commit();
}

///////////////////////////////////////////////////////////////////////////////
// struct Regular

Regular::result_type Regular::operator()(const request_type& request_)
{
	if (!request_.isTemplate())
		return base_type::operator()(request_);

	return getScript()().execute();
}

} // namespace Template

///////////////////////////////////////////////////////////////////////////////
// struct Vm

Vm::result_type Vm::operator()(const request_type& request_)
{
	if (request_.isTemplate())
		return PRL_ERR_UNEXPECTED;

	if (request_.getItems().isEmpty())
	{
		getScript()
			.withTeardown(Command::Delete::Backup
				(request_.getHome(), request_.getVm()));
	}

	return getScript()().execute();
}

} // namespace Delete

///////////////////////////////////////////////////////////////////////////////
// struct Unregister

Unregister::result_type Unregister::operator()(const request_type& request_)
{
	if (request_.isTemplate())
		return PRL_ERR_SUCCESS;

	return getScript()
		.withDisable(Command::Delete::Backup
			(request_.getHome(), request_.getVm()))().execute();
}

} // namespace Chain
} // namespace Instrument
