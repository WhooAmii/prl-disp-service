/*
 * Copyright (c) 2015-2017, Parallels International GmbH
 * Copyright (c) 2017-2019 Virtuozzo International GmbH. All rights reserved.
 *
 * This file is part of Virtuozzo Core Libraries. Virtuozzo Core
 * Libraries is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see
 * <http://www.gnu.org/licenses/> or write to Free Software Foundation,
 * 51 Franklin Street, Fifth Floor Boston, MA 02110, USA.
 *
 * Our contact details: Virtuozzo International GmbH, Vordergasse 59, 8200
 * Schaffhausen, Switzerland.
 */

#ifndef __SNAPSHOT_TYPE_H__
#define __SNAPSHOT_TYPE_H__
#include "base.h"
#include "snapshot_data.h"
#include "snapshot_enum.h"
#include "patterns.h"
#include "domain_type.h"
#include <boost/any.hpp>

namespace Libvirt
{

///////////////////////////////////////////////////////////////////////////////
// struct VMemory

namespace Snapshot
{
namespace Xml
{
typedef Choice<mpl::vector<Attribute<Snapshot::Xml::ESnapshot, Name::Strict<462> >, Ordered<mpl::vector<Optional<Attribute<mpl::int_<464>, Name::Strict<462> > >, Attribute<Snapshot::Xml::PAbsFilePath, Name::Strict<500> > > > > > VMemoryImpl;
typedef VMemoryImpl::value_type VMemory;

} // namespace Xml
} // namespace Snapshot

///////////////////////////////////////////////////////////////////////////////
// struct Disk4021

namespace Snapshot
{
namespace Xml
{
struct Disk4021
{
};

} // namespace Xml
} // namespace Snapshot

///////////////////////////////////////////////////////////////////////////////
// struct Disk4022

namespace Snapshot
{
namespace Xml
{
struct Disk4022
{
};

} // namespace Xml
} // namespace Snapshot

///////////////////////////////////////////////////////////////////////////////
// struct Source

namespace Snapshot
{
namespace Xml
{
struct Source
{
	const boost::optional<PAbsFilePath::value_type >& getFile() const
	{
		return m_file;
	}
	void setFile(const boost::optional<PAbsFilePath::value_type >& value_)
	{
		m_file = value_;
	}
	const boost::optional<EStartupPolicy >& getStartupPolicy() const
	{
		return m_startupPolicy;
	}
	void setStartupPolicy(const boost::optional<EStartupPolicy >& value_)
	{
		m_startupPolicy = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<PAbsFilePath::value_type > m_file;
	boost::optional<EStartupPolicy > m_startupPolicy;
};

} // namespace Xml
} // namespace Snapshot

///////////////////////////////////////////////////////////////////////////////
// struct Driver

namespace Snapshot
{
namespace Xml
{
struct Driver
{
	const boost::optional<EStorageFormatBacking >& getType() const
	{
		return m_type;
	}
	void setType(const boost::optional<EStorageFormatBacking >& value_)
	{
		m_type = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<EStorageFormatBacking > m_type;
};

} // namespace Xml
} // namespace Snapshot

///////////////////////////////////////////////////////////////////////////////
// struct Variant4016

namespace Snapshot
{
namespace Xml
{
struct Variant4016
{
	const boost::optional<Source >& getSource() const
	{
		return m_source;
	}
	void setSource(const boost::optional<Source >& value_)
	{
		m_source = value_;
	}
	const boost::optional<Driver >& getDriver() const
	{
		return m_driver;
	}
	void setDriver(const boost::optional<Driver >& value_)
	{
		m_driver = value_;
	}

private:
	boost::optional<Source > m_source;
	boost::optional<Driver > m_driver;
};

} // namespace Xml
} // namespace Snapshot

///////////////////////////////////////////////////////////////////////////////
// struct Variant4017

namespace Snapshot
{
namespace Xml
{
struct Variant4017
{
	const boost::optional<PAbsFilePath::value_type >& getSource() const
	{
		return m_source;
	}
	void setSource(const boost::optional<PAbsFilePath::value_type >& value_)
	{
		m_source = value_;
	}
	const boost::optional<Driver >& getDriver() const
	{
		return m_driver;
	}
	void setDriver(const boost::optional<Driver >& value_)
	{
		m_driver = value_;
	}

private:
	boost::optional<PAbsFilePath::value_type > m_source;
	boost::optional<Driver > m_driver;
};

} // namespace Xml
} // namespace Snapshot

///////////////////////////////////////////////////////////////////////////////
// struct Host4383

namespace Snapshot
{
namespace Xml
{
struct Host4383
{
	const boost::optional<ETransport >& getTransport() const
	{
		return m_transport;
	}
	void setTransport(const boost::optional<ETransport >& value_)
	{
		m_transport = value_;
	}
	const VName1& getName() const
	{
		return m_name;
	}
	void setName(const VName1& value_)
	{
		m_name = value_;
	}
	const boost::optional<PUnsignedInt::value_type >& getPort() const
	{
		return m_port;
	}
	void setPort(const boost::optional<PUnsignedInt::value_type >& value_)
	{
		m_port = value_;
	}

private:
	boost::optional<ETransport > m_transport;
	VName1 m_name;
	boost::optional<PUnsignedInt::value_type > m_port;
};

} // namespace Xml
} // namespace Snapshot

///////////////////////////////////////////////////////////////////////////////
// struct VHost

namespace Snapshot
{
namespace Xml
{
typedef Choice<mpl::vector<Host4383, Ordered<mpl::vector<Attribute<mpl::int_<520>, Name::Strict<514> >, Attribute<Snapshot::Xml::PAbsFilePath, Name::Strict<521> > > > > > VHostImpl;
typedef VHostImpl::value_type VHost;

} // namespace Xml
} // namespace Snapshot

///////////////////////////////////////////////////////////////////////////////
// struct Source1

namespace Snapshot
{
namespace Xml
{
struct Source1
{
	Source1();

	EProtocol getProtocol() const
	{
		return m_protocol;
	}
	void setProtocol(EProtocol value_)
	{
		m_protocol = value_;
	}
	const boost::optional<QString >& getName() const
	{
		return m_name;
	}
	void setName(const boost::optional<QString >& value_)
	{
		m_name = value_;
	}
	const QList<VHost >& getHostList() const
	{
		return m_hostList;
	}
	void setHostList(const QList<VHost >& value_)
	{
		m_hostList = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	EProtocol m_protocol;
	boost::optional<QString > m_name;
	QList<VHost > m_hostList;
};

} // namespace Xml
} // namespace Snapshot

///////////////////////////////////////////////////////////////////////////////
// struct VChoice4019

namespace Snapshot
{
namespace Xml
{
typedef Choice<mpl::vector<Variant4016, Variant4017, Ordered<mpl::vector<Attribute<mpl::int_<445>, Name::Strict<105> >, Element<Snapshot::Xml::Source1, Name::Strict<501> > > > > > VChoice4019Impl;
typedef VChoice4019Impl::value_type VChoice4019;

} // namespace Xml
} // namespace Snapshot

///////////////////////////////////////////////////////////////////////////////
// struct VDisk

namespace Snapshot
{
namespace Xml
{
typedef Choice<mpl::vector<Disk4021, Disk4022, Ordered<mpl::vector<Optional<Attribute<mpl::int_<464>, Name::Strict<462> > >, Snapshot::Xml::VChoice4019Impl > > > > VDiskImpl;
typedef VDiskImpl::value_type VDisk;

} // namespace Xml
} // namespace Snapshot

///////////////////////////////////////////////////////////////////////////////
// struct Disk

namespace Snapshot
{
namespace Xml
{
struct Disk
{
	const VName& getName() const
	{
		return m_name;
	}
	void setName(const VName& value_)
	{
		m_name = value_;
	}
	const VDisk& getDisk() const
	{
		return m_disk;
	}
	void setDisk(const VDisk& value_)
	{
		m_disk = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	VName m_name;
	VDisk m_disk;
};

} // namespace Xml
} // namespace Snapshot

///////////////////////////////////////////////////////////////////////////////
// struct VChoice4011

namespace Snapshot
{
namespace Xml
{
typedef Choice<mpl::vector<Element<Element<Text<Snapshot::Xml::VUUID >, Name::Strict<151> >, Name::Strict<1> >, Element<Domain::Xml::Domain, Name::Strict<1> > > > VChoice4011Impl;
typedef VChoice4011Impl::value_type VChoice4011;

} // namespace Xml
} // namespace Snapshot

///////////////////////////////////////////////////////////////////////////////
// struct Domainsnapshot

namespace Snapshot
{
namespace Xml
{
struct Domainsnapshot
{
	const boost::optional<QString >& getName() const
	{
		return m_name;
	}
	void setName(const boost::optional<QString >& value_)
	{
		m_name = value_;
	}
	const boost::optional<QString >& getDescription() const
	{
		return m_description;
	}
	void setDescription(const boost::optional<QString >& value_)
	{
		m_description = value_;
	}
	const boost::optional<EState >& getState() const
	{
		return m_state;
	}
	void setState(const boost::optional<EState >& value_)
	{
		m_state = value_;
	}
	const boost::optional<QString >& getCreationTime() const
	{
		return m_creationTime;
	}
	void setCreationTime(const boost::optional<QString >& value_)
	{
		m_creationTime = value_;
	}
	const boost::optional<VMemory >& getMemory() const
	{
		return m_memory;
	}
	void setMemory(const boost::optional<VMemory >& value_)
	{
		m_memory = value_;
	}
	const boost::optional<QList<Disk > >& getDisks() const
	{
		return m_disks;
	}
	void setDisks(const boost::optional<QList<Disk > >& value_)
	{
		m_disks = value_;
	}
	const boost::optional<EActive >& getActive() const
	{
		return m_active;
	}
	void setActive(const boost::optional<EActive >& value_)
	{
		m_active = value_;
	}
	const boost::optional<VChoice4011 >& getChoice4011() const
	{
		return m_choice4011;
	}
	void setChoice4011(const boost::optional<VChoice4011 >& value_)
	{
		m_choice4011 = value_;
	}
	const boost::optional<Domain::Xml::Domain >& getXPersistent() const
	{
		return m_xPersistent;
	}
	void setXPersistent(const boost::optional<Domain::Xml::Domain >& value_)
	{
		m_xPersistent = value_;
	}
	const boost::optional<QString >& getParent() const
	{
		return m_parent;
	}
	void setParent(const boost::optional<QString >& value_)
	{
		m_parent = value_;
	}
	const boost::optional<QList<QDomElement > >& getCookie() const
	{
		return m_cookie;
	}
	void setCookie(const boost::optional<QList<QDomElement > >& value_)
	{
		m_cookie = value_;
	}
	bool load(const QDomElement& );
	bool save(QDomElement& ) const;
	bool save(QDomDocument& ) const;

private:
	boost::optional<QString > m_name;
	boost::optional<QString > m_description;
	boost::optional<EState > m_state;
	boost::optional<QString > m_creationTime;
	boost::optional<VMemory > m_memory;
	boost::optional<QList<Disk > > m_disks;
	boost::optional<EActive > m_active;
	boost::optional<VChoice4011 > m_choice4011;
	boost::optional<Domain::Xml::Domain > m_xPersistent;
	boost::optional<QString > m_parent;
	boost::optional<QList<QDomElement > > m_cookie;
};

} // namespace Xml
} // namespace Snapshot

///////////////////////////////////////////////////////////////////////////////
// struct Disk4021 traits

template<>
struct Traits<Snapshot::Xml::Disk4021>
{
	typedef Attribute<mpl::int_<136>, Name::Strict<462> > marshal_type;

	static int parse(Snapshot::Xml::Disk4021& , QStack<QDomElement>& );
	static int generate(const Snapshot::Xml::Disk4021& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Disk4022 traits

template<>
struct Traits<Snapshot::Xml::Disk4022>
{
	typedef Attribute<mpl::int_<463>, Name::Strict<462> > marshal_type;

	static int parse(Snapshot::Xml::Disk4022& , QStack<QDomElement>& );
	static int generate(const Snapshot::Xml::Disk4022& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Source traits

template<>
struct Traits<Snapshot::Xml::Source>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Snapshot::Xml::PAbsFilePath, Name::Strict<500> > >, Optional<Attribute<Snapshot::Xml::EStartupPolicy, Name::Strict<468> > > > > marshal_type;

	static int parse(Snapshot::Xml::Source& , QStack<QDomElement>& );
	static int generate(const Snapshot::Xml::Source& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Driver traits

template<>
struct Traits<Snapshot::Xml::Driver>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Snapshot::Xml::EStorageFormatBacking, Name::Strict<105> > > > > marshal_type;

	static int parse(Snapshot::Xml::Driver& , QStack<QDomElement>& );
	static int generate(const Snapshot::Xml::Driver& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Variant4016 traits

template<>
struct Traits<Snapshot::Xml::Variant4016>
{
	typedef Ordered<mpl::vector<Optional<Attribute<mpl::int_<500>, Name::Strict<105> > >, Unordered<mpl::vector<Optional<Element<Snapshot::Xml::Source, Name::Strict<501> > >, Optional<Element<Snapshot::Xml::Driver, Name::Strict<546> > > > > > > marshal_type;

	static int parse(Snapshot::Xml::Variant4016& , QStack<QDomElement>& );
	static int generate(const Snapshot::Xml::Variant4016& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Variant4017 traits

template<>
struct Traits<Snapshot::Xml::Variant4017>
{
	typedef Ordered<mpl::vector<Attribute<mpl::int_<502>, Name::Strict<105> >, Unordered<mpl::vector<Optional<Element<Attribute<Snapshot::Xml::PAbsFilePath, Name::Strict<441> >, Name::Strict<501> > >, Optional<Element<Snapshot::Xml::Driver, Name::Strict<546> > > > > > > marshal_type;

	static int parse(Snapshot::Xml::Variant4017& , QStack<QDomElement>& );
	static int generate(const Snapshot::Xml::Variant4017& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Host4383 traits

template<>
struct Traits<Snapshot::Xml::Host4383>
{
	typedef Ordered<mpl::vector<Optional<Attribute<Snapshot::Xml::ETransport, Name::Strict<514> > >, Attribute<Snapshot::Xml::VName1, Name::Strict<107> >, Optional<Attribute<Snapshot::Xml::PUnsignedInt, Name::Strict<212> > > > > marshal_type;

	static int parse(Snapshot::Xml::Host4383& , QStack<QDomElement>& );
	static int generate(const Snapshot::Xml::Host4383& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Source1 traits

template<>
struct Traits<Snapshot::Xml::Source1>
{
	typedef Ordered<mpl::vector<Attribute<Snapshot::Xml::EProtocol, Name::Strict<203> >, Optional<Attribute<QString, Name::Strict<107> > >, ZeroOrMore<Element<Snapshot::Xml::VHostImpl, Name::Strict<513> > > > > marshal_type;

	static int parse(Snapshot::Xml::Source1& , QStack<QDomElement>& );
	static int generate(const Snapshot::Xml::Source1& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Disk traits

template<>
struct Traits<Snapshot::Xml::Disk>
{
	typedef Ordered<mpl::vector<Attribute<Snapshot::Xml::VName, Name::Strict<107> >, Snapshot::Xml::VDiskImpl > > marshal_type;

	static int parse(Snapshot::Xml::Disk& , QStack<QDomElement>& );
	static int generate(const Snapshot::Xml::Disk& , QDomElement& );
};

///////////////////////////////////////////////////////////////////////////////
// struct Domainsnapshot traits

template<>
struct Traits<Snapshot::Xml::Domainsnapshot>
{
	typedef Unordered<mpl::vector<Optional<Element<Text<QString >, Name::Strict<107> > >, Optional<Element<Text<QString >, Name::Strict<216> > >, Optional<Element<Text<Snapshot::Xml::EState >, Name::Strict<126> > >, Optional<Element<Text<QString >, Name::Strict<1584> > >, Optional<Element<Snapshot::Xml::VMemoryImpl, Name::Strict<326> > >, Optional<Element<ZeroOrMore<Element<Snapshot::Xml::Disk, Name::Strict<472> > >, Name::Strict<1587> > >, Optional<Element<Text<Snapshot::Xml::EActive >, Name::Strict<1342> > >, Optional<Snapshot::Xml::VChoice4011Impl >, Optional<Element<Element<Domain::Xml::Domain, Name::Strict<1> >, Name::Strict<4295> > >, Optional<Element<Element<Text<QString >, Name::Strict<107> >, Name::Strict<116> > >, Optional<Element<ZeroOrMore<Pod >, Name::Strict<1817> > > > > marshal_type;

	static int parse(Snapshot::Xml::Domainsnapshot& , QStack<QDomElement>& );
	static int generate(const Snapshot::Xml::Domainsnapshot& , QDomElement& );
};

} // namespace Libvirt

#endif // __SNAPSHOT_TYPE_H__
