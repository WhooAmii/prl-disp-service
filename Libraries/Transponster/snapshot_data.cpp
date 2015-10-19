/*
 * Copyright (c) 2015 Parallels IP Holdings GmbH
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
 * Our contact details: Parallels IP Holdings GmbH, Vordergasse 59, 8200
 * Schaffhausen, Switzerland.
 */

#include "snapshot_data.h"
#include <QRegExp>

namespace Libvirt
{
///////////////////////////////////////////////////////////////////////////////
// struct PUnsignedInt

bool Traits<Snapshot::Xml::PUnsignedInt>::parse(const QString& src_, Snapshot::Xml::PUnsignedInt::value_type& dst_)
{
	QRegExp q("[0-9]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PUnsignedInt>::generate(Snapshot::Xml::PUnsignedInt::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PUnsignedLong

bool Traits<Snapshot::Xml::PUnsignedLong>::parse(const QString& src_, Snapshot::Xml::PUnsignedLong::value_type& dst_)
{
	QRegExp q("[0-9]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toULong(&output);
	return output;
}

QString Traits<Snapshot::Xml::PUnsignedLong>::generate(Snapshot::Xml::PUnsignedLong::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PPositiveInteger

bool Traits<Snapshot::Xml::PPositiveInteger>::parse(const QString& src_, Snapshot::Xml::PPositiveInteger::value_type& dst_)
{
	QRegExp q("[0-9]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PPositiveInteger>::generate(Snapshot::Xml::PPositiveInteger::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct POctalMode

bool Traits<Snapshot::Xml::POctalMode>::parse(const QString& src_, Snapshot::Xml::POctalMode::value_type& dst_)
{
	QRegExp q("[0-7]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::POctalMode>::generate(Snapshot::Xml::POctalMode::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PData1268

bool Validatable<Snapshot::Xml::PData1268>::validate(const Snapshot::Xml::PData1268::value_type& value_)
{
	QRegExp q("0x[0-9a-fA-F]{1,2}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData1270

bool Traits<Snapshot::Xml::PData1270>::parse(const QString& src_, Snapshot::Xml::PData1270::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PData1270>::generate(Snapshot::Xml::PData1270::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PData1270>::validate(Snapshot::Xml::PData1270::value_type value_)
{
	if (0 > value_)
		return false;

	if (255 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData1272

bool Validatable<Snapshot::Xml::PData1272>::validate(const Snapshot::Xml::PData1272::value_type& value_)
{
	QRegExp q("0x[0-9a-fA-F]{1,6}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData1274

bool Traits<Snapshot::Xml::PData1274>::parse(const QString& src_, Snapshot::Xml::PData1274::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PData1274>::generate(Snapshot::Xml::PData1274::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PData1274>::validate(Snapshot::Xml::PData1274::value_type value_)
{
	if (0 > value_)
		return false;

	if (16777215 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData1276

bool Validatable<Snapshot::Xml::PData1276>::validate(const Snapshot::Xml::PData1276::value_type& value_)
{
	QRegExp q("[a-fA-F0-9]{32}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData1278

bool Validatable<Snapshot::Xml::PData1278>::validate(const Snapshot::Xml::PData1278::value_type& value_)
{
	QRegExp q("[a-fA-F0-9]{8}\\-([a-fA-F0-9]{4}\\-){3}[a-fA-F0-9]{12}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PUniMacAddr

bool Validatable<Snapshot::Xml::PUniMacAddr>::validate(const Snapshot::Xml::PUniMacAddr::value_type& value_)
{
	QRegExp q("[a-fA-F0-9][02468aAcCeE](:[a-fA-F0-9]{2}){5}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PMultiMacAddr

bool Validatable<Snapshot::Xml::PMultiMacAddr>::validate(const Snapshot::Xml::PMultiMacAddr::value_type& value_)
{
	QRegExp q("[a-fA-F0-9][13579bBdDfF](:[a-fA-F0-9]{2}){5}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PMacAddr

bool Validatable<Snapshot::Xml::PMacAddr>::validate(const Snapshot::Xml::PMacAddr::value_type& value_)
{
	QRegExp q("[a-fA-F0-9]{2}(:[a-fA-F0-9]{2}){5}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDuidLLT

bool Validatable<Snapshot::Xml::PDuidLLT>::validate(const Snapshot::Xml::PDuidLLT::value_type& value_)
{
	QRegExp q("[0]{1,2}:[0]{0,1}[1]:[0]{1,2}:[0]{0,1}[a-fA-F1-9](:[a-fA-F0-9]{1,2}){4}(:[a-fA-F0-9]{1,2}){6,8}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDuidEN

bool Validatable<Snapshot::Xml::PDuidEN>::validate(const Snapshot::Xml::PDuidEN::value_type& value_)
{
	QRegExp q("[0]{1,2}:[0]{0,1}[2](:[a-fA-F0-9]{1,2}){4}(:[a-fA-F0-9]{1,2}){1,124}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDuidLL

bool Validatable<Snapshot::Xml::PDuidLL>::validate(const Snapshot::Xml::PDuidLL::value_type& value_)
{
	QRegExp q("[0]{1,2}:[0]{0,1}[3]:[0]{1,2}:[0]{0,1}[a-fA-F1-9](:[a-fA-F0-9]{1,2}){6,8}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDuidUUID

bool Validatable<Snapshot::Xml::PDuidUUID>::validate(const Snapshot::Xml::PDuidUUID::value_type& value_)
{
	QRegExp q("[0]{1,2}:[0]{0,1}[4](:[a-fA-F0-9]{1,2}){16}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PIpv4Addr

bool Validatable<Snapshot::Xml::PIpv4Addr>::validate(const Snapshot::Xml::PIpv4Addr::value_type& value_)
{
	QRegExp q("(((25[0-5])|(2[0-4][0-9])|(1[0-9]{2})|([1-9][0-9])|([0-9]))\\.){3}((25[0-5])|(2[0-4][0-9])|(1[0-9]{2})|([1-9][0-9])|([0-9]))");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PIpv6Addr

bool Validatable<Snapshot::Xml::PIpv6Addr>::validate(const Snapshot::Xml::PIpv6Addr::value_type& value_)
{
	QRegExp q("(([0-9A-Fa-f]{1,4}:){7}[0-9A-Fa-f]{1,4})|(([0-9A-Fa-f]{1,4}:){6}:[0-9A-Fa-f]{1,4})|(([0-9A-Fa-f]{1,4}:){5}:([0-9A-Fa-f]{1,4}:)?[0-9A-Fa-f]{1,4})|(([0-9A-Fa-f]{1,4}:){4}:([0-9A-Fa-f]{1,4}:){0,2}[0-9A-Fa-f]{1,4})|(([0-9A-Fa-f]{1,4}:){3}:([0-9A-Fa-f]{1,4}:){0,3}[0-9A-Fa-f]{1,4})|(([0-9A-Fa-f]{1,4}:){2}:([0-9A-Fa-f]{1,4}:){0,4}[0-9A-Fa-f]{1,4})|(([0-9A-Fa-f]{1,4}:){6}(((25[0-5])|(2[0-4][0-9])|(1[0-9]{2})|([1-9][0-9])|([0-9]))\\.){3}((25[0-5])|(2[0-4][0-9])|(1[0-9]{2})|([1-9][0-9])|([0-9])))|(([0-9A-Fa-f]{1,4}:){0,5}:(((25[0-5])|(2[0-4][0-9])|(1[0-9]{2})|([1-9][0-9])|([0-9]))\\.){3}((25[0-5])|(2[0-4][0-9])|(1[0-9]{2})|([1-9][0-9])|([0-9])))|(::([0-9A-Fa-f]{1,4}:){0,5}(((25[0-5])|(2[0-4][0-9])|(1[0-9]{2})|([1-9][0-9])|([0-9]))\\.){3}((25[0-5])|(2[0-4][0-9])|(1[0-9]{2})|([1-9][0-9])|([0-9])))|([0-9A-Fa-f]{1,4}::([0-9A-Fa-f]{1,4}:){0,5}[0-9A-Fa-f]{1,4})|(::([0-9A-Fa-f]{1,4}:){0,6}[0-9A-Fa-f]{1,4})|(([0-9A-Fa-f]{1,4}:){1,7}:)");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PIpv4Prefix

bool Traits<Snapshot::Xml::PIpv4Prefix>::parse(const QString& src_, Snapshot::Xml::PIpv4Prefix::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PIpv4Prefix>::generate(Snapshot::Xml::PIpv4Prefix::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PIpv4Prefix>::validate(Snapshot::Xml::PIpv4Prefix::value_type value_)
{
	if (32 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PIpv6Prefix

bool Traits<Snapshot::Xml::PIpv6Prefix>::parse(const QString& src_, Snapshot::Xml::PIpv6Prefix::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PIpv6Prefix>::generate(Snapshot::Xml::PIpv6Prefix::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PIpv6Prefix>::validate(Snapshot::Xml::PIpv6Prefix::value_type value_)
{
	if (128 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PGenericName

bool Validatable<Snapshot::Xml::PGenericName>::validate(const Snapshot::Xml::PGenericName::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9_\\+\\-]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDnsName

bool Validatable<Snapshot::Xml::PDnsName>::validate(const Snapshot::Xml::PDnsName::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9\\.\\-]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDeviceName

bool Validatable<Snapshot::Xml::PDeviceName>::validate(const Snapshot::Xml::PDeviceName::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9_\\.\\-\\\\:/]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PFilePath

bool Validatable<Snapshot::Xml::PFilePath>::validate(const Snapshot::Xml::PFilePath::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9_\\.\\+\\-\\\\&\"{}'<>/%]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDirPath

bool Validatable<Snapshot::Xml::PDirPath>::validate(const Snapshot::Xml::PDirPath::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9_\\.\\+\\-\\\\&\"{}'<>/%]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PAbsFilePath

bool Validatable<Snapshot::Xml::PAbsFilePath>::validate(const Snapshot::Xml::PAbsFilePath::value_type& value_)
{
	QRegExp q("/[a-zA-Z0-9_\\.\\+\\-\\\\&\"{}'<>/%,]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PAbsDirPath

bool Validatable<Snapshot::Xml::PAbsDirPath>::validate(const Snapshot::Xml::PAbsDirPath::value_type& value_)
{
	QRegExp q("/[a-zA-Z0-9_\\.\\+\\-\\\\&\"{}'<>/%]*");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PUnit

bool Validatable<Snapshot::Xml::PUnit>::validate(const Snapshot::Xml::PUnit::value_type& value_)
{
	QRegExp q("([bB]([yY][tT][eE][sS]?)?)|([kKmMgGtTpPeE]([iI]?[bB])?)");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PPciDomain

bool Validatable<Snapshot::Xml::PPciDomain>::validate(const Snapshot::Xml::PPciDomain::value_type& value_)
{
	QRegExp q("(0x)?[0-9a-fA-F]{1,4}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PPciBus

bool Validatable<Snapshot::Xml::PPciBus>::validate(const Snapshot::Xml::PPciBus::value_type& value_)
{
	QRegExp q("(0x)?[0-9a-fA-F]{1,2}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PPciSlot

bool Validatable<Snapshot::Xml::PPciSlot>::validate(const Snapshot::Xml::PPciSlot::value_type& value_)
{
	QRegExp q("(0x)?[0-1]?[0-9a-fA-F]");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PPciFunc

bool Validatable<Snapshot::Xml::PPciFunc>::validate(const Snapshot::Xml::PPciFunc::value_type& value_)
{
	QRegExp q("(0x)?[0-7]");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PWwn

bool Validatable<Snapshot::Xml::PWwn>::validate(const Snapshot::Xml::PWwn::value_type& value_)
{
	QRegExp q("(0x)?[0-9a-fA-F]{16}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PCpuset

bool Validatable<Snapshot::Xml::PCpuset>::validate(const Snapshot::Xml::PCpuset::value_type& value_)
{
	QRegExp q("([0-9]+(-[0-9]+)?|\\^[0-9]+)(,([0-9]+(-[0-9]+)?|\\^[0-9]+))*");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PVolName

bool Validatable<Snapshot::Xml::PVolName>::validate(const Snapshot::Xml::PVolName::value_type& value_)
{
	if ("\n        " == value_)
		return false;

	QRegExp q("[^/]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PPortNumber

bool Traits<Snapshot::Xml::PPortNumber>::parse(const QString& src_, Snapshot::Xml::PPortNumber::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toShort(&output);
	return output;
}

QString Traits<Snapshot::Xml::PPortNumber>::generate(Snapshot::Xml::PPortNumber::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PPortNumber>::validate(Snapshot::Xml::PPortNumber::value_type value_)
{
	if (-1 > value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PIobase

bool Validatable<Snapshot::Xml::PIobase>::validate(const Snapshot::Xml::PIobase::value_type& value_)
{
	QRegExp q("0x[a-fA-F0-9]{1,4}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PIrq

bool Validatable<Snapshot::Xml::PIrq>::validate(const Snapshot::Xml::PIrq::value_type& value_)
{
	QRegExp q("0x[a-fA-F0-9]");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PCompat

bool Validatable<Snapshot::Xml::PCompat>::validate(const Snapshot::Xml::PCompat::value_type& value_)
{
	QRegExp q("[0-9]+\\.[0-9]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PVirtualPortProfileID

bool Validatable<Snapshot::Xml::PVirtualPortProfileID>::validate(const Snapshot::Xml::PVirtualPortProfileID::value_type& value_)
{
	if (39 < value_.length())
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PSpeed

bool Traits<Snapshot::Xml::PSpeed>::parse(const QString& src_, Snapshot::Xml::PSpeed::value_type& dst_)
{
	QRegExp q("[0-9]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PSpeed>::generate(Snapshot::Xml::PSpeed::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PSpeed>::validate(Snapshot::Xml::PSpeed::value_type value_)
{
	if (1 > value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PBurstSize

bool Traits<Snapshot::Xml::PBurstSize>::parse(const QString& src_, Snapshot::Xml::PBurstSize::value_type& dst_)
{
	QRegExp q("[0-9]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PBurstSize>::generate(Snapshot::Xml::PBurstSize::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PBurstSize>::validate(Snapshot::Xml::PBurstSize::value_type value_)
{
	if (1 > value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PUnsignedShort

bool Traits<Snapshot::Xml::PUnsignedShort>::parse(const QString& src_, Snapshot::Xml::PUnsignedShort::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PUnsignedShort>::generate(Snapshot::Xml::PUnsignedShort::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PUnsignedShort>::validate(Snapshot::Xml::PUnsignedShort::value_type value_)
{
	if (0 > value_)
		return false;

	if (65535 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PProtocol

bool Validatable<Snapshot::Xml::PProtocol>::validate(const Snapshot::Xml::PProtocol::value_type& value_)
{
	QRegExp q("(tcp)|(udp)");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PAddrFamily

bool Validatable<Snapshot::Xml::PAddrFamily>::validate(const Snapshot::Xml::PAddrFamily::value_type& value_)
{
	QRegExp q("(ipv4)|(ipv6)");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PId

bool Traits<Snapshot::Xml::PId>::parse(const QString& src_, Snapshot::Xml::PId::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PId>::generate(Snapshot::Xml::PId::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PId>::validate(Snapshot::Xml::PId::value_type value_)
{
	if (4095 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PPort

bool Traits<Snapshot::Xml::PPort>::parse(const QString& src_, Snapshot::Xml::PPort::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PPort>::generate(Snapshot::Xml::PPort::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PPort>::validate(Snapshot::Xml::PPort::value_type value_)
{
	if (1 > value_)
		return false;

	if (65535 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PTitle

bool Validatable<Snapshot::Xml::PTitle>::validate(const Snapshot::Xml::PTitle::value_type& value_)
{
	QRegExp q("[^\n]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PMachine

bool Validatable<Snapshot::Xml::PMachine>::validate(const Snapshot::Xml::PMachine::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9_\\.\\-]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PMachine1

bool Validatable<Snapshot::Xml::PMachine1>::validate(const Snapshot::Xml::PMachine1::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9_\\.\\-]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PMachine2

bool Validatable<Snapshot::Xml::PMachine2>::validate(const Snapshot::Xml::PMachine2::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9_\\.\\-]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PReadIopsSec

bool Traits<Snapshot::Xml::PReadIopsSec>::parse(const QString& src_, Snapshot::Xml::PReadIopsSec::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PReadIopsSec>::generate(Snapshot::Xml::PReadIopsSec::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PWriteIopsSec

bool Traits<Snapshot::Xml::PWriteIopsSec>::parse(const QString& src_, Snapshot::Xml::PWriteIopsSec::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PWriteIopsSec>::generate(Snapshot::Xml::PWriteIopsSec::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PReadBytesSec

bool Traits<Snapshot::Xml::PReadBytesSec>::parse(const QString& src_, Snapshot::Xml::PReadBytesSec::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toULong(&output);
	return output;
}

QString Traits<Snapshot::Xml::PReadBytesSec>::generate(Snapshot::Xml::PReadBytesSec::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PWriteBytesSec

bool Traits<Snapshot::Xml::PWriteBytesSec>::parse(const QString& src_, Snapshot::Xml::PWriteBytesSec::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toULong(&output);
	return output;
}

QString Traits<Snapshot::Xml::PWriteBytesSec>::generate(Snapshot::Xml::PWriteBytesSec::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PVendor

bool Validatable<Snapshot::Xml::PVendor>::validate(const Snapshot::Xml::PVendor::value_type& value_)
{
	QRegExp q("[x20-x7E]{0,8}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PProduct

bool Validatable<Snapshot::Xml::PProduct>::validate(const Snapshot::Xml::PProduct::value_type& value_)
{
	QRegExp q("[x20-x7E]{0,16}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDiskTarget

bool Validatable<Snapshot::Xml::PDiskTarget>::validate(const Snapshot::Xml::PDiskTarget::value_type& value_)
{
	QRegExp q("(ioemu:)?(fd|hd|sd|vd|xvd|ubd)[a-zA-Z0-9_]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PCyls

bool Traits<Snapshot::Xml::PCyls>::parse(const QString& src_, Snapshot::Xml::PCyls::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PCyls>::generate(Snapshot::Xml::PCyls::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PHeads

bool Traits<Snapshot::Xml::PHeads>::parse(const QString& src_, Snapshot::Xml::PHeads::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PHeads>::generate(Snapshot::Xml::PHeads::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PSecs

bool Traits<Snapshot::Xml::PSecs>::parse(const QString& src_, Snapshot::Xml::PSecs::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PSecs>::generate(Snapshot::Xml::PSecs::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PLogicalBlockSize

bool Traits<Snapshot::Xml::PLogicalBlockSize>::parse(const QString& src_, Snapshot::Xml::PLogicalBlockSize::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PLogicalBlockSize>::generate(Snapshot::Xml::PLogicalBlockSize::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PPhysicalBlockSize

bool Traits<Snapshot::Xml::PPhysicalBlockSize>::parse(const QString& src_, Snapshot::Xml::PPhysicalBlockSize::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PPhysicalBlockSize>::generate(Snapshot::Xml::PPhysicalBlockSize::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PType

bool Validatable<Snapshot::Xml::PType>::validate(const Snapshot::Xml::PType::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9\\-_]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PPasswdValidTo

bool Traits<Snapshot::Xml::PPasswdValidTo>::parse(const QString& src_, Snapshot::Xml::PPasswdValidTo::value_type& dst_)
{
	dst_ = QDateTime::fromString(src_);
	return !dst_.isNull();
}

QString Traits<Snapshot::Xml::PPasswdValidTo>::generate(const Snapshot::Xml::PPasswdValidTo::value_type& src_)
{
	return src_.toString();
}

///////////////////////////////////////////////////////////////////////////////
// struct PPasswdValidTo1

bool Traits<Snapshot::Xml::PPasswdValidTo1>::parse(const QString& src_, Snapshot::Xml::PPasswdValidTo1::value_type& dst_)
{
	dst_ = QDateTime::fromString(src_);
	return !dst_.isNull();
}

QString Traits<Snapshot::Xml::PPasswdValidTo1>::generate(const Snapshot::Xml::PPasswdValidTo1::value_type& src_)
{
	return src_.toString();
}

///////////////////////////////////////////////////////////////////////////////
// struct PVendorId

bool Validatable<Snapshot::Xml::PVendorId>::validate(const Snapshot::Xml::PVendorId::value_type& value_)
{
	QRegExp q("[^,]{12}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PSysinfoValue

bool Validatable<Snapshot::Xml::PSysinfoValue>::validate(const Snapshot::Xml::PSysinfoValue::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9/\\-_\\. \\(\\)]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PTotalBytesSec

bool Traits<Snapshot::Xml::PTotalBytesSec>::parse(const QString& src_, Snapshot::Xml::PTotalBytesSec::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toULong(&output);
	return output;
}

QString Traits<Snapshot::Xml::PTotalBytesSec>::generate(Snapshot::Xml::PTotalBytesSec::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PReadBytesSec1

bool Traits<Snapshot::Xml::PReadBytesSec1>::parse(const QString& src_, Snapshot::Xml::PReadBytesSec1::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toULong(&output);
	return output;
}

QString Traits<Snapshot::Xml::PReadBytesSec1>::generate(Snapshot::Xml::PReadBytesSec1::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PWriteBytesSec1

bool Traits<Snapshot::Xml::PWriteBytesSec1>::parse(const QString& src_, Snapshot::Xml::PWriteBytesSec1::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toULong(&output);
	return output;
}

QString Traits<Snapshot::Xml::PWriteBytesSec1>::generate(Snapshot::Xml::PWriteBytesSec1::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PTotalIopsSec

bool Traits<Snapshot::Xml::PTotalIopsSec>::parse(const QString& src_, Snapshot::Xml::PTotalIopsSec::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toULong(&output);
	return output;
}

QString Traits<Snapshot::Xml::PTotalIopsSec>::generate(Snapshot::Xml::PTotalIopsSec::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PReadIopsSec1

bool Traits<Snapshot::Xml::PReadIopsSec1>::parse(const QString& src_, Snapshot::Xml::PReadIopsSec1::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toULong(&output);
	return output;
}

QString Traits<Snapshot::Xml::PReadIopsSec1>::generate(Snapshot::Xml::PReadIopsSec1::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PWriteIopsSec1

bool Traits<Snapshot::Xml::PWriteIopsSec1>::parse(const QString& src_, Snapshot::Xml::PWriteIopsSec1::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toULong(&output);
	return output;
}

QString Traits<Snapshot::Xml::PWriteIopsSec1>::generate(Snapshot::Xml::PWriteIopsSec1::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PRetries

bool Traits<Snapshot::Xml::PRetries>::parse(const QString& src_, Snapshot::Xml::PRetries::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PRetries>::generate(Snapshot::Xml::PRetries::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PCountCPU

bool Traits<Snapshot::Xml::PCountCPU>::parse(const QString& src_, Snapshot::Xml::PCountCPU::value_type& dst_)
{
	QRegExp q("[0-9]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toUShort(&output);
	return output;
}

QString Traits<Snapshot::Xml::PCountCPU>::generate(Snapshot::Xml::PCountCPU::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PCountCPU>::validate(Snapshot::Xml::PCountCPU::value_type value_)
{
	if (1 > value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PVcpuid

bool Traits<Snapshot::Xml::PVcpuid>::parse(const QString& src_, Snapshot::Xml::PVcpuid::value_type& dst_)
{
	QRegExp q("[0-9]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toUShort(&output);
	return output;
}

QString Traits<Snapshot::Xml::PVcpuid>::generate(Snapshot::Xml::PVcpuid::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PCpushares

bool Traits<Snapshot::Xml::PCpushares>::parse(const QString& src_, Snapshot::Xml::PCpushares::value_type& dst_)
{
	QRegExp q("[0-9]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PCpushares>::generate(Snapshot::Xml::PCpushares::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PCpuperiod

bool Traits<Snapshot::Xml::PCpuperiod>::parse(const QString& src_, Snapshot::Xml::PCpuperiod::value_type& dst_)
{
	QRegExp q("[0-9]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toULong(&output);
	return output;
}

QString Traits<Snapshot::Xml::PCpuperiod>::generate(Snapshot::Xml::PCpuperiod::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PCpuperiod>::validate(Snapshot::Xml::PCpuperiod::value_type value_)
{
	if (1000 > value_)
		return false;

	if (1000000 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PCpuquota

bool Traits<Snapshot::Xml::PCpuquota>::parse(const QString& src_, Snapshot::Xml::PCpuquota::value_type& dst_)
{
	QRegExp q("-?[0-9]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toLong(&output);
	return output;
}

QString Traits<Snapshot::Xml::PCpuquota>::generate(Snapshot::Xml::PCpuquota::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PCpuquota>::validate(Snapshot::Xml::PCpuquota::value_type value_)
{
	if (-1 > value_)
		return false;

	if (18446744073709551 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PRebootTimeoutDelay

bool Traits<Snapshot::Xml::PRebootTimeoutDelay>::parse(const QString& src_, Snapshot::Xml::PRebootTimeoutDelay::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toShort(&output);
	return output;
}

QString Traits<Snapshot::Xml::PRebootTimeoutDelay>::generate(Snapshot::Xml::PRebootTimeoutDelay::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PRebootTimeoutDelay>::validate(Snapshot::Xml::PRebootTimeoutDelay::value_type value_)
{
	if (-1 > value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PWeight

bool Traits<Snapshot::Xml::PWeight>::parse(const QString& src_, Snapshot::Xml::PWeight::value_type& dst_)
{
	QRegExp q("[0-9]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PWeight>::generate(Snapshot::Xml::PWeight::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PWeight>::validate(Snapshot::Xml::PWeight::value_type value_)
{
	if (100 > value_)
		return false;

	if (1000 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PMemoryKB

bool Traits<Snapshot::Xml::PMemoryKB>::parse(const QString& src_, Snapshot::Xml::PMemoryKB::value_type& dst_)
{
	QRegExp q("[0-9]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PMemoryKB>::generate(Snapshot::Xml::PMemoryKB::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PDomainName

bool Validatable<Snapshot::Xml::PDomainName>::validate(const Snapshot::Xml::PDomainName::value_type& value_)
{
	QRegExp q("[^\n]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDiskSerial

bool Validatable<Snapshot::Xml::PDiskSerial>::validate(const Snapshot::Xml::PDiskSerial::value_type& value_)
{
	QRegExp q("[A-Za-z0-9_\\.\\+\\-]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PBridgeMode

bool Validatable<Snapshot::Xml::PBridgeMode>::validate(const Snapshot::Xml::PBridgeMode::value_type& value_)
{
	QRegExp q("(vepa|bridge|private|passthrough)");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PAddrIPorName

bool Validatable<Snapshot::Xml::PAddrIPorName>::validate(const Snapshot::Xml::PAddrIPorName::value_type& value_)
{
	QRegExp q("(([0-2]?[0-9]?[0-9]\\.){3}[0-2]?[0-9]?[0-9])|(([0-9a-fA-F]+|:)+[0-9a-fA-F]+)|([a-zA-Z0-9_\\.\\+\\-]*)");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PUsbIdDefault

bool Validatable<Snapshot::Xml::PUsbIdDefault>::validate(const Snapshot::Xml::PUsbIdDefault::value_type& value_)
{
	QRegExp q("-1");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PUsbId

bool Validatable<Snapshot::Xml::PUsbId>::validate(const Snapshot::Xml::PUsbId::value_type& value_)
{
	QRegExp q("(0x)?[0-9a-fA-F]{1,4}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PUsbVersion

bool Validatable<Snapshot::Xml::PUsbVersion>::validate(const Snapshot::Xml::PUsbVersion::value_type& value_)
{
	QRegExp q("[0-9]{1,2}.[0-9]{1,2}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PUsbAddr

bool Validatable<Snapshot::Xml::PUsbAddr>::validate(const Snapshot::Xml::PUsbAddr::value_type& value_)
{
	QRegExp q("(0x)?[0-9a-fA-F]{1,3}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PUsbClass

bool Validatable<Snapshot::Xml::PUsbClass>::validate(const Snapshot::Xml::PUsbClass::value_type& value_)
{
	QRegExp q("(0x)?[0-9a-fA-F]{1,2}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PUsbPort

bool Validatable<Snapshot::Xml::PUsbPort>::validate(const Snapshot::Xml::PUsbPort::value_type& value_)
{
	QRegExp q("((0x)?[0-9a-fA-F]{1,3}\\.){0,3}(0x)?[0-9a-fA-F]{1,3}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDriveController

bool Validatable<Snapshot::Xml::PDriveController>::validate(const Snapshot::Xml::PDriveController::value_type& value_)
{
	QRegExp q("[0-9]{1,2}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDriveBus

bool Validatable<Snapshot::Xml::PDriveBus>::validate(const Snapshot::Xml::PDriveBus::value_type& value_)
{
	QRegExp q("[0-9]{1,2}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDriveTarget

bool Validatable<Snapshot::Xml::PDriveTarget>::validate(const Snapshot::Xml::PDriveTarget::value_type& value_)
{
	QRegExp q("[0-9]{1,2}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDriveUnit

bool Validatable<Snapshot::Xml::PDriveUnit>::validate(const Snapshot::Xml::PDriveUnit::value_type& value_)
{
	QRegExp q("[0-9]{1,2}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PFeatureName

bool Validatable<Snapshot::Xml::PFeatureName>::validate(const Snapshot::Xml::PFeatureName::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9\\-_\\.]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PTimeDelta

bool Validatable<Snapshot::Xml::PTimeDelta>::validate(const Snapshot::Xml::PTimeDelta::value_type& value_)
{
	QRegExp q("(-|\\+)?[0-9]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PTimeZone

bool Validatable<Snapshot::Xml::PTimeZone>::validate(const Snapshot::Xml::PTimeZone::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9_\\.\\+\\-/]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PFilterParamName

bool Validatable<Snapshot::Xml::PFilterParamName>::validate(const Snapshot::Xml::PFilterParamName::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9_]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PFilterParamValue

bool Validatable<Snapshot::Xml::PFilterParamValue>::validate(const Snapshot::Xml::PFilterParamValue::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9_\\.:]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PSpaprvioReg

bool Validatable<Snapshot::Xml::PSpaprvioReg>::validate(const Snapshot::Xml::PSpaprvioReg::value_type& value_)
{
	QRegExp q("(0x)?[0-9a-fA-F]{1,16}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PAliasName

bool Validatable<Snapshot::Xml::PAliasName>::validate(const Snapshot::Xml::PAliasName::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9_\\-.]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData1473

bool Validatable<Snapshot::Xml::PData1473>::validate(const Snapshot::Xml::PData1473::value_type& value_)
{
	QRegExp q("0x[0-9a-eA-E][0-9a-fA-F]?");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData1475

bool Validatable<Snapshot::Xml::PData1475>::validate(const Snapshot::Xml::PData1475::value_type& value_)
{
	QRegExp q("0x[fF][0-9a-eA-E]?");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData1477

bool Traits<Snapshot::Xml::PData1477>::parse(const QString& src_, Snapshot::Xml::PData1477::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PData1477>::generate(Snapshot::Xml::PData1477::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PData1477>::validate(Snapshot::Xml::PData1477::value_type value_)
{
	if (0 > value_)
		return false;

	if (254 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PCcwSsidRange

bool Validatable<Snapshot::Xml::PCcwSsidRange>::validate(const Snapshot::Xml::PCcwSsidRange::value_type& value_)
{
	QRegExp q("(0x)?[0-3]");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData1479

bool Validatable<Snapshot::Xml::PData1479>::validate(const Snapshot::Xml::PData1479::value_type& value_)
{
	QRegExp q("0x[0-9a-fA-F]{1,4}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData1481

bool Traits<Snapshot::Xml::PData1481>::parse(const QString& src_, Snapshot::Xml::PData1481::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PData1481>::generate(Snapshot::Xml::PData1481::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PData1481>::validate(Snapshot::Xml::PData1481::value_type value_)
{
	if (0 > value_)
		return false;

	if (65535 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PUnsignedInt1

bool Traits<Snapshot::Xml::PUnsignedInt1>::parse(const QString& src_, Snapshot::Xml::PUnsignedInt1::value_type& dst_)
{
	QRegExp q("[0-9]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PUnsignedInt1>::generate(Snapshot::Xml::PUnsignedInt1::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PUnsignedLong1

bool Traits<Snapshot::Xml::PUnsignedLong1>::parse(const QString& src_, Snapshot::Xml::PUnsignedLong1::value_type& dst_)
{
	QRegExp q("[0-9]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toULong(&output);
	return output;
}

QString Traits<Snapshot::Xml::PUnsignedLong1>::generate(Snapshot::Xml::PUnsignedLong1::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PPositiveInteger1

bool Traits<Snapshot::Xml::PPositiveInteger1>::parse(const QString& src_, Snapshot::Xml::PPositiveInteger1::value_type& dst_)
{
	QRegExp q("[0-9]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PPositiveInteger1>::generate(Snapshot::Xml::PPositiveInteger1::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct POctalMode1

bool Traits<Snapshot::Xml::POctalMode1>::parse(const QString& src_, Snapshot::Xml::POctalMode1::value_type& dst_)
{
	QRegExp q("[0-7]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::POctalMode1>::generate(Snapshot::Xml::POctalMode1::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PData1491

bool Validatable<Snapshot::Xml::PData1491>::validate(const Snapshot::Xml::PData1491::value_type& value_)
{
	QRegExp q("0x[0-9a-fA-F]{1,2}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData1493

bool Traits<Snapshot::Xml::PData1493>::parse(const QString& src_, Snapshot::Xml::PData1493::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PData1493>::generate(Snapshot::Xml::PData1493::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PData1493>::validate(Snapshot::Xml::PData1493::value_type value_)
{
	if (0 > value_)
		return false;

	if (255 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData1495

bool Validatable<Snapshot::Xml::PData1495>::validate(const Snapshot::Xml::PData1495::value_type& value_)
{
	QRegExp q("0x[0-9a-fA-F]{1,6}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData1497

bool Traits<Snapshot::Xml::PData1497>::parse(const QString& src_, Snapshot::Xml::PData1497::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PData1497>::generate(Snapshot::Xml::PData1497::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PData1497>::validate(Snapshot::Xml::PData1497::value_type value_)
{
	if (0 > value_)
		return false;

	if (16777215 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData1499

bool Validatable<Snapshot::Xml::PData1499>::validate(const Snapshot::Xml::PData1499::value_type& value_)
{
	QRegExp q("[a-fA-F0-9]{32}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData1501

bool Validatable<Snapshot::Xml::PData1501>::validate(const Snapshot::Xml::PData1501::value_type& value_)
{
	QRegExp q("[a-fA-F0-9]{8}\\-([a-fA-F0-9]{4}\\-){3}[a-fA-F0-9]{12}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PUniMacAddr1

bool Validatable<Snapshot::Xml::PUniMacAddr1>::validate(const Snapshot::Xml::PUniMacAddr1::value_type& value_)
{
	QRegExp q("[a-fA-F0-9][02468aAcCeE](:[a-fA-F0-9]{2}){5}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PMultiMacAddr1

bool Validatable<Snapshot::Xml::PMultiMacAddr1>::validate(const Snapshot::Xml::PMultiMacAddr1::value_type& value_)
{
	QRegExp q("[a-fA-F0-9][13579bBdDfF](:[a-fA-F0-9]{2}){5}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PMacAddr1

bool Validatable<Snapshot::Xml::PMacAddr1>::validate(const Snapshot::Xml::PMacAddr1::value_type& value_)
{
	QRegExp q("[a-fA-F0-9]{2}(:[a-fA-F0-9]{2}){5}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDuidLLT1

bool Validatable<Snapshot::Xml::PDuidLLT1>::validate(const Snapshot::Xml::PDuidLLT1::value_type& value_)
{
	QRegExp q("[0]{1,2}:[0]{0,1}[1]:[0]{1,2}:[0]{0,1}[a-fA-F1-9](:[a-fA-F0-9]{1,2}){4}(:[a-fA-F0-9]{1,2}){6,8}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDuidEN1

bool Validatable<Snapshot::Xml::PDuidEN1>::validate(const Snapshot::Xml::PDuidEN1::value_type& value_)
{
	QRegExp q("[0]{1,2}:[0]{0,1}[2](:[a-fA-F0-9]{1,2}){4}(:[a-fA-F0-9]{1,2}){1,124}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDuidLL1

bool Validatable<Snapshot::Xml::PDuidLL1>::validate(const Snapshot::Xml::PDuidLL1::value_type& value_)
{
	QRegExp q("[0]{1,2}:[0]{0,1}[3]:[0]{1,2}:[0]{0,1}[a-fA-F1-9](:[a-fA-F0-9]{1,2}){6,8}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDuidUUID1

bool Validatable<Snapshot::Xml::PDuidUUID1>::validate(const Snapshot::Xml::PDuidUUID1::value_type& value_)
{
	QRegExp q("[0]{1,2}:[0]{0,1}[4](:[a-fA-F0-9]{1,2}){16}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PIpv4Addr1

bool Validatable<Snapshot::Xml::PIpv4Addr1>::validate(const Snapshot::Xml::PIpv4Addr1::value_type& value_)
{
	QRegExp q("(((25[0-5])|(2[0-4][0-9])|(1[0-9]{2})|([1-9][0-9])|([0-9]))\\.){3}((25[0-5])|(2[0-4][0-9])|(1[0-9]{2})|([1-9][0-9])|([0-9]))");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PIpv6Addr1

bool Validatable<Snapshot::Xml::PIpv6Addr1>::validate(const Snapshot::Xml::PIpv6Addr1::value_type& value_)
{
	QRegExp q("(([0-9A-Fa-f]{1,4}:){7}[0-9A-Fa-f]{1,4})|(([0-9A-Fa-f]{1,4}:){6}:[0-9A-Fa-f]{1,4})|(([0-9A-Fa-f]{1,4}:){5}:([0-9A-Fa-f]{1,4}:)?[0-9A-Fa-f]{1,4})|(([0-9A-Fa-f]{1,4}:){4}:([0-9A-Fa-f]{1,4}:){0,2}[0-9A-Fa-f]{1,4})|(([0-9A-Fa-f]{1,4}:){3}:([0-9A-Fa-f]{1,4}:){0,3}[0-9A-Fa-f]{1,4})|(([0-9A-Fa-f]{1,4}:){2}:([0-9A-Fa-f]{1,4}:){0,4}[0-9A-Fa-f]{1,4})|(([0-9A-Fa-f]{1,4}:){6}(((25[0-5])|(2[0-4][0-9])|(1[0-9]{2})|([1-9][0-9])|([0-9]))\\.){3}((25[0-5])|(2[0-4][0-9])|(1[0-9]{2})|([1-9][0-9])|([0-9])))|(([0-9A-Fa-f]{1,4}:){0,5}:(((25[0-5])|(2[0-4][0-9])|(1[0-9]{2})|([1-9][0-9])|([0-9]))\\.){3}((25[0-5])|(2[0-4][0-9])|(1[0-9]{2})|([1-9][0-9])|([0-9])))|(::([0-9A-Fa-f]{1,4}:){0,5}(((25[0-5])|(2[0-4][0-9])|(1[0-9]{2})|([1-9][0-9])|([0-9]))\\.){3}((25[0-5])|(2[0-4][0-9])|(1[0-9]{2})|([1-9][0-9])|([0-9])))|([0-9A-Fa-f]{1,4}::([0-9A-Fa-f]{1,4}:){0,5}[0-9A-Fa-f]{1,4})|(::([0-9A-Fa-f]{1,4}:){0,6}[0-9A-Fa-f]{1,4})|(([0-9A-Fa-f]{1,4}:){1,7}:)");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PIpv4Prefix1

bool Traits<Snapshot::Xml::PIpv4Prefix1>::parse(const QString& src_, Snapshot::Xml::PIpv4Prefix1::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PIpv4Prefix1>::generate(Snapshot::Xml::PIpv4Prefix1::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PIpv4Prefix1>::validate(Snapshot::Xml::PIpv4Prefix1::value_type value_)
{
	if (32 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PIpv6Prefix1

bool Traits<Snapshot::Xml::PIpv6Prefix1>::parse(const QString& src_, Snapshot::Xml::PIpv6Prefix1::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PIpv6Prefix1>::generate(Snapshot::Xml::PIpv6Prefix1::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PIpv6Prefix1>::validate(Snapshot::Xml::PIpv6Prefix1::value_type value_)
{
	if (128 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PGenericName1

bool Validatable<Snapshot::Xml::PGenericName1>::validate(const Snapshot::Xml::PGenericName1::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9_\\+\\-]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDnsName1

bool Validatable<Snapshot::Xml::PDnsName1>::validate(const Snapshot::Xml::PDnsName1::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9\\.\\-]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDeviceName1

bool Validatable<Snapshot::Xml::PDeviceName1>::validate(const Snapshot::Xml::PDeviceName1::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9_\\.\\-\\\\:/]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PFilePath1

bool Validatable<Snapshot::Xml::PFilePath1>::validate(const Snapshot::Xml::PFilePath1::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9_\\.\\+\\-\\\\&\"{}'<>/%]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDirPath1

bool Validatable<Snapshot::Xml::PDirPath1>::validate(const Snapshot::Xml::PDirPath1::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9_\\.\\+\\-\\\\&\"{}'<>/%]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PAbsFilePath1

bool Validatable<Snapshot::Xml::PAbsFilePath1>::validate(const Snapshot::Xml::PAbsFilePath1::value_type& value_)
{
	QRegExp q("/[a-zA-Z0-9_\\.\\+\\-\\\\&\"{}'<>/%,]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PAbsDirPath1

bool Validatable<Snapshot::Xml::PAbsDirPath1>::validate(const Snapshot::Xml::PAbsDirPath1::value_type& value_)
{
	QRegExp q("/[a-zA-Z0-9_\\.\\+\\-\\\\&\"{}'<>/%]*");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PUnit1

bool Validatable<Snapshot::Xml::PUnit1>::validate(const Snapshot::Xml::PUnit1::value_type& value_)
{
	QRegExp q("([bB]([yY][tT][eE][sS]?)?)|([kKmMgGtTpPeE]([iI]?[bB])?)");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PPciDomain1

bool Validatable<Snapshot::Xml::PPciDomain1>::validate(const Snapshot::Xml::PPciDomain1::value_type& value_)
{
	QRegExp q("(0x)?[0-9a-fA-F]{1,4}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PPciBus1

bool Validatable<Snapshot::Xml::PPciBus1>::validate(const Snapshot::Xml::PPciBus1::value_type& value_)
{
	QRegExp q("(0x)?[0-9a-fA-F]{1,2}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PPciSlot1

bool Validatable<Snapshot::Xml::PPciSlot1>::validate(const Snapshot::Xml::PPciSlot1::value_type& value_)
{
	QRegExp q("(0x)?[0-1]?[0-9a-fA-F]");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PPciFunc1

bool Validatable<Snapshot::Xml::PPciFunc1>::validate(const Snapshot::Xml::PPciFunc1::value_type& value_)
{
	QRegExp q("(0x)?[0-7]");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PWwn1

bool Validatable<Snapshot::Xml::PWwn1>::validate(const Snapshot::Xml::PWwn1::value_type& value_)
{
	QRegExp q("(0x)?[0-9a-fA-F]{16}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PCpuset1

bool Validatable<Snapshot::Xml::PCpuset1>::validate(const Snapshot::Xml::PCpuset1::value_type& value_)
{
	QRegExp q("([0-9]+(-[0-9]+)?|\\^[0-9]+)(,([0-9]+(-[0-9]+)?|\\^[0-9]+))*");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PVolName1

bool Validatable<Snapshot::Xml::PVolName1>::validate(const Snapshot::Xml::PVolName1::value_type& value_)
{
	if ("\n        " == value_)
		return false;

	QRegExp q("[^/]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PPortNumber1

bool Traits<Snapshot::Xml::PPortNumber1>::parse(const QString& src_, Snapshot::Xml::PPortNumber1::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toShort(&output);
	return output;
}

QString Traits<Snapshot::Xml::PPortNumber1>::generate(Snapshot::Xml::PPortNumber1::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PPortNumber1>::validate(Snapshot::Xml::PPortNumber1::value_type value_)
{
	if (-1 > value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PIobase1

bool Validatable<Snapshot::Xml::PIobase1>::validate(const Snapshot::Xml::PIobase1::value_type& value_)
{
	QRegExp q("0x[a-fA-F0-9]{1,4}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PIrq1

bool Validatable<Snapshot::Xml::PIrq1>::validate(const Snapshot::Xml::PIrq1::value_type& value_)
{
	QRegExp q("0x[a-fA-F0-9]");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PCompat1

bool Validatable<Snapshot::Xml::PCompat1>::validate(const Snapshot::Xml::PCompat1::value_type& value_)
{
	QRegExp q("[0-9]+\\.[0-9]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PVirtualPortProfileID1

bool Validatable<Snapshot::Xml::PVirtualPortProfileID1>::validate(const Snapshot::Xml::PVirtualPortProfileID1::value_type& value_)
{
	if (39 < value_.length())
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PSpeed1

bool Traits<Snapshot::Xml::PSpeed1>::parse(const QString& src_, Snapshot::Xml::PSpeed1::value_type& dst_)
{
	QRegExp q("[0-9]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PSpeed1>::generate(Snapshot::Xml::PSpeed1::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PSpeed1>::validate(Snapshot::Xml::PSpeed1::value_type value_)
{
	if (1 > value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PBurstSize1

bool Traits<Snapshot::Xml::PBurstSize1>::parse(const QString& src_, Snapshot::Xml::PBurstSize1::value_type& dst_)
{
	QRegExp q("[0-9]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PBurstSize1>::generate(Snapshot::Xml::PBurstSize1::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PBurstSize1>::validate(Snapshot::Xml::PBurstSize1::value_type value_)
{
	if (1 > value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PUnsignedShort1

bool Traits<Snapshot::Xml::PUnsignedShort1>::parse(const QString& src_, Snapshot::Xml::PUnsignedShort1::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PUnsignedShort1>::generate(Snapshot::Xml::PUnsignedShort1::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PUnsignedShort1>::validate(Snapshot::Xml::PUnsignedShort1::value_type value_)
{
	if (0 > value_)
		return false;

	if (65535 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PProtocol1

bool Validatable<Snapshot::Xml::PProtocol1>::validate(const Snapshot::Xml::PProtocol1::value_type& value_)
{
	QRegExp q("(tcp)|(udp)");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PAddrFamily1

bool Validatable<Snapshot::Xml::PAddrFamily1>::validate(const Snapshot::Xml::PAddrFamily1::value_type& value_)
{
	QRegExp q("(ipv4)|(ipv6)");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PId1

bool Traits<Snapshot::Xml::PId1>::parse(const QString& src_, Snapshot::Xml::PId1::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PId1>::generate(Snapshot::Xml::PId1::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PId1>::validate(Snapshot::Xml::PId1::value_type value_)
{
	if (4095 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PPort1

bool Traits<Snapshot::Xml::PPort1>::parse(const QString& src_, Snapshot::Xml::PPort1::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PPort1>::generate(Snapshot::Xml::PPort1::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PPort1>::validate(Snapshot::Xml::PPort1::value_type value_)
{
	if (1 > value_)
		return false;

	if (65535 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PTitle1

bool Validatable<Snapshot::Xml::PTitle1>::validate(const Snapshot::Xml::PTitle1::value_type& value_)
{
	QRegExp q("[^\n]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PMachine3

bool Validatable<Snapshot::Xml::PMachine3>::validate(const Snapshot::Xml::PMachine3::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9_\\.\\-]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PMachine4

bool Validatable<Snapshot::Xml::PMachine4>::validate(const Snapshot::Xml::PMachine4::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9_\\.\\-]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PMachine5

bool Validatable<Snapshot::Xml::PMachine5>::validate(const Snapshot::Xml::PMachine5::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9_\\.\\-]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PReadIopsSec2

bool Traits<Snapshot::Xml::PReadIopsSec2>::parse(const QString& src_, Snapshot::Xml::PReadIopsSec2::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PReadIopsSec2>::generate(Snapshot::Xml::PReadIopsSec2::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PWriteIopsSec2

bool Traits<Snapshot::Xml::PWriteIopsSec2>::parse(const QString& src_, Snapshot::Xml::PWriteIopsSec2::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PWriteIopsSec2>::generate(Snapshot::Xml::PWriteIopsSec2::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PReadBytesSec2

bool Traits<Snapshot::Xml::PReadBytesSec2>::parse(const QString& src_, Snapshot::Xml::PReadBytesSec2::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toULong(&output);
	return output;
}

QString Traits<Snapshot::Xml::PReadBytesSec2>::generate(Snapshot::Xml::PReadBytesSec2::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PWriteBytesSec2

bool Traits<Snapshot::Xml::PWriteBytesSec2>::parse(const QString& src_, Snapshot::Xml::PWriteBytesSec2::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toULong(&output);
	return output;
}

QString Traits<Snapshot::Xml::PWriteBytesSec2>::generate(Snapshot::Xml::PWriteBytesSec2::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PVendor1

bool Validatable<Snapshot::Xml::PVendor1>::validate(const Snapshot::Xml::PVendor1::value_type& value_)
{
	QRegExp q("[x20-x7E]{0,8}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PProduct1

bool Validatable<Snapshot::Xml::PProduct1>::validate(const Snapshot::Xml::PProduct1::value_type& value_)
{
	QRegExp q("[x20-x7E]{0,16}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDiskTarget1

bool Validatable<Snapshot::Xml::PDiskTarget1>::validate(const Snapshot::Xml::PDiskTarget1::value_type& value_)
{
	QRegExp q("(ioemu:)?(fd|hd|sd|vd|xvd|ubd)[a-zA-Z0-9_]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PCyls1

bool Traits<Snapshot::Xml::PCyls1>::parse(const QString& src_, Snapshot::Xml::PCyls1::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PCyls1>::generate(Snapshot::Xml::PCyls1::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PHeads1

bool Traits<Snapshot::Xml::PHeads1>::parse(const QString& src_, Snapshot::Xml::PHeads1::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PHeads1>::generate(Snapshot::Xml::PHeads1::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PSecs1

bool Traits<Snapshot::Xml::PSecs1>::parse(const QString& src_, Snapshot::Xml::PSecs1::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PSecs1>::generate(Snapshot::Xml::PSecs1::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PLogicalBlockSize1

bool Traits<Snapshot::Xml::PLogicalBlockSize1>::parse(const QString& src_, Snapshot::Xml::PLogicalBlockSize1::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PLogicalBlockSize1>::generate(Snapshot::Xml::PLogicalBlockSize1::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PPhysicalBlockSize1

bool Traits<Snapshot::Xml::PPhysicalBlockSize1>::parse(const QString& src_, Snapshot::Xml::PPhysicalBlockSize1::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PPhysicalBlockSize1>::generate(Snapshot::Xml::PPhysicalBlockSize1::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PType1

bool Validatable<Snapshot::Xml::PType1>::validate(const Snapshot::Xml::PType1::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9\\-_]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PPasswdValidTo2

bool Traits<Snapshot::Xml::PPasswdValidTo2>::parse(const QString& src_, Snapshot::Xml::PPasswdValidTo2::value_type& dst_)
{
	dst_ = QDateTime::fromString(src_);
	return !dst_.isNull();
}

QString Traits<Snapshot::Xml::PPasswdValidTo2>::generate(const Snapshot::Xml::PPasswdValidTo2::value_type& src_)
{
	return src_.toString();
}

///////////////////////////////////////////////////////////////////////////////
// struct PPasswdValidTo3

bool Traits<Snapshot::Xml::PPasswdValidTo3>::parse(const QString& src_, Snapshot::Xml::PPasswdValidTo3::value_type& dst_)
{
	dst_ = QDateTime::fromString(src_);
	return !dst_.isNull();
}

QString Traits<Snapshot::Xml::PPasswdValidTo3>::generate(const Snapshot::Xml::PPasswdValidTo3::value_type& src_)
{
	return src_.toString();
}

///////////////////////////////////////////////////////////////////////////////
// struct PVendorId1

bool Validatable<Snapshot::Xml::PVendorId1>::validate(const Snapshot::Xml::PVendorId1::value_type& value_)
{
	QRegExp q("[^,]{12}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PSysinfoValue1

bool Validatable<Snapshot::Xml::PSysinfoValue1>::validate(const Snapshot::Xml::PSysinfoValue1::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9/\\-_\\. \\(\\)]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PTotalBytesSec1

bool Traits<Snapshot::Xml::PTotalBytesSec1>::parse(const QString& src_, Snapshot::Xml::PTotalBytesSec1::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toULong(&output);
	return output;
}

QString Traits<Snapshot::Xml::PTotalBytesSec1>::generate(Snapshot::Xml::PTotalBytesSec1::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PReadBytesSec3

bool Traits<Snapshot::Xml::PReadBytesSec3>::parse(const QString& src_, Snapshot::Xml::PReadBytesSec3::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toULong(&output);
	return output;
}

QString Traits<Snapshot::Xml::PReadBytesSec3>::generate(Snapshot::Xml::PReadBytesSec3::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PWriteBytesSec3

bool Traits<Snapshot::Xml::PWriteBytesSec3>::parse(const QString& src_, Snapshot::Xml::PWriteBytesSec3::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toULong(&output);
	return output;
}

QString Traits<Snapshot::Xml::PWriteBytesSec3>::generate(Snapshot::Xml::PWriteBytesSec3::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PTotalIopsSec1

bool Traits<Snapshot::Xml::PTotalIopsSec1>::parse(const QString& src_, Snapshot::Xml::PTotalIopsSec1::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toULong(&output);
	return output;
}

QString Traits<Snapshot::Xml::PTotalIopsSec1>::generate(Snapshot::Xml::PTotalIopsSec1::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PReadIopsSec3

bool Traits<Snapshot::Xml::PReadIopsSec3>::parse(const QString& src_, Snapshot::Xml::PReadIopsSec3::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toULong(&output);
	return output;
}

QString Traits<Snapshot::Xml::PReadIopsSec3>::generate(Snapshot::Xml::PReadIopsSec3::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PWriteIopsSec3

bool Traits<Snapshot::Xml::PWriteIopsSec3>::parse(const QString& src_, Snapshot::Xml::PWriteIopsSec3::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toULong(&output);
	return output;
}

QString Traits<Snapshot::Xml::PWriteIopsSec3>::generate(Snapshot::Xml::PWriteIopsSec3::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PRetries1

bool Traits<Snapshot::Xml::PRetries1>::parse(const QString& src_, Snapshot::Xml::PRetries1::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PRetries1>::generate(Snapshot::Xml::PRetries1::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PCountCPU1

bool Traits<Snapshot::Xml::PCountCPU1>::parse(const QString& src_, Snapshot::Xml::PCountCPU1::value_type& dst_)
{
	QRegExp q("[0-9]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toUShort(&output);
	return output;
}

QString Traits<Snapshot::Xml::PCountCPU1>::generate(Snapshot::Xml::PCountCPU1::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PCountCPU1>::validate(Snapshot::Xml::PCountCPU1::value_type value_)
{
	if (1 > value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PVcpuid1

bool Traits<Snapshot::Xml::PVcpuid1>::parse(const QString& src_, Snapshot::Xml::PVcpuid1::value_type& dst_)
{
	QRegExp q("[0-9]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toUShort(&output);
	return output;
}

QString Traits<Snapshot::Xml::PVcpuid1>::generate(Snapshot::Xml::PVcpuid1::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PCpushares1

bool Traits<Snapshot::Xml::PCpushares1>::parse(const QString& src_, Snapshot::Xml::PCpushares1::value_type& dst_)
{
	QRegExp q("[0-9]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PCpushares1>::generate(Snapshot::Xml::PCpushares1::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PCpuperiod1

bool Traits<Snapshot::Xml::PCpuperiod1>::parse(const QString& src_, Snapshot::Xml::PCpuperiod1::value_type& dst_)
{
	QRegExp q("[0-9]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toULong(&output);
	return output;
}

QString Traits<Snapshot::Xml::PCpuperiod1>::generate(Snapshot::Xml::PCpuperiod1::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PCpuperiod1>::validate(Snapshot::Xml::PCpuperiod1::value_type value_)
{
	if (1000 > value_)
		return false;

	if (1000000 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PCpuquota1

bool Traits<Snapshot::Xml::PCpuquota1>::parse(const QString& src_, Snapshot::Xml::PCpuquota1::value_type& dst_)
{
	QRegExp q("-?[0-9]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toLong(&output);
	return output;
}

QString Traits<Snapshot::Xml::PCpuquota1>::generate(Snapshot::Xml::PCpuquota1::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PCpuquota1>::validate(Snapshot::Xml::PCpuquota1::value_type value_)
{
	if (-1 > value_)
		return false;

	if (18446744073709551 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PRebootTimeoutDelay1

bool Traits<Snapshot::Xml::PRebootTimeoutDelay1>::parse(const QString& src_, Snapshot::Xml::PRebootTimeoutDelay1::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toShort(&output);
	return output;
}

QString Traits<Snapshot::Xml::PRebootTimeoutDelay1>::generate(Snapshot::Xml::PRebootTimeoutDelay1::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PRebootTimeoutDelay1>::validate(Snapshot::Xml::PRebootTimeoutDelay1::value_type value_)
{
	if (-1 > value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PWeight1

bool Traits<Snapshot::Xml::PWeight1>::parse(const QString& src_, Snapshot::Xml::PWeight1::value_type& dst_)
{
	QRegExp q("[0-9]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PWeight1>::generate(Snapshot::Xml::PWeight1::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PWeight1>::validate(Snapshot::Xml::PWeight1::value_type value_)
{
	if (100 > value_)
		return false;

	if (1000 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PMemoryKB1

bool Traits<Snapshot::Xml::PMemoryKB1>::parse(const QString& src_, Snapshot::Xml::PMemoryKB1::value_type& dst_)
{
	QRegExp q("[0-9]+");
	if (!q.exactMatch(src_))
		return false;
	bool output = false;
	dst_ = src_.toUInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PMemoryKB1>::generate(Snapshot::Xml::PMemoryKB1::value_type src_)
{
	return QString::number(src_);
}

///////////////////////////////////////////////////////////////////////////////
// struct PDomainName1

bool Validatable<Snapshot::Xml::PDomainName1>::validate(const Snapshot::Xml::PDomainName1::value_type& value_)
{
	QRegExp q("[^\n]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDiskSerial1

bool Validatable<Snapshot::Xml::PDiskSerial1>::validate(const Snapshot::Xml::PDiskSerial1::value_type& value_)
{
	QRegExp q("[A-Za-z0-9_\\.\\+\\-]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PBridgeMode1

bool Validatable<Snapshot::Xml::PBridgeMode1>::validate(const Snapshot::Xml::PBridgeMode1::value_type& value_)
{
	QRegExp q("(vepa|bridge|private|passthrough)");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PAddrIPorName1

bool Validatable<Snapshot::Xml::PAddrIPorName1>::validate(const Snapshot::Xml::PAddrIPorName1::value_type& value_)
{
	QRegExp q("(([0-2]?[0-9]?[0-9]\\.){3}[0-2]?[0-9]?[0-9])|(([0-9a-fA-F]+|:)+[0-9a-fA-F]+)|([a-zA-Z0-9_\\.\\+\\-]*)");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PUsbIdDefault1

bool Validatable<Snapshot::Xml::PUsbIdDefault1>::validate(const Snapshot::Xml::PUsbIdDefault1::value_type& value_)
{
	QRegExp q("-1");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PUsbId1

bool Validatable<Snapshot::Xml::PUsbId1>::validate(const Snapshot::Xml::PUsbId1::value_type& value_)
{
	QRegExp q("(0x)?[0-9a-fA-F]{1,4}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PUsbVersion1

bool Validatable<Snapshot::Xml::PUsbVersion1>::validate(const Snapshot::Xml::PUsbVersion1::value_type& value_)
{
	QRegExp q("[0-9]{1,2}.[0-9]{1,2}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PUsbAddr1

bool Validatable<Snapshot::Xml::PUsbAddr1>::validate(const Snapshot::Xml::PUsbAddr1::value_type& value_)
{
	QRegExp q("(0x)?[0-9a-fA-F]{1,3}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PUsbClass1

bool Validatable<Snapshot::Xml::PUsbClass1>::validate(const Snapshot::Xml::PUsbClass1::value_type& value_)
{
	QRegExp q("(0x)?[0-9a-fA-F]{1,2}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PUsbPort1

bool Validatable<Snapshot::Xml::PUsbPort1>::validate(const Snapshot::Xml::PUsbPort1::value_type& value_)
{
	QRegExp q("((0x)?[0-9a-fA-F]{1,3}\\.){0,3}(0x)?[0-9a-fA-F]{1,3}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDriveController1

bool Validatable<Snapshot::Xml::PDriveController1>::validate(const Snapshot::Xml::PDriveController1::value_type& value_)
{
	QRegExp q("[0-9]{1,2}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDriveBus1

bool Validatable<Snapshot::Xml::PDriveBus1>::validate(const Snapshot::Xml::PDriveBus1::value_type& value_)
{
	QRegExp q("[0-9]{1,2}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDriveTarget1

bool Validatable<Snapshot::Xml::PDriveTarget1>::validate(const Snapshot::Xml::PDriveTarget1::value_type& value_)
{
	QRegExp q("[0-9]{1,2}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PDriveUnit1

bool Validatable<Snapshot::Xml::PDriveUnit1>::validate(const Snapshot::Xml::PDriveUnit1::value_type& value_)
{
	QRegExp q("[0-9]{1,2}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PFeatureName1

bool Validatable<Snapshot::Xml::PFeatureName1>::validate(const Snapshot::Xml::PFeatureName1::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9\\-_\\.]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PTimeDelta1

bool Validatable<Snapshot::Xml::PTimeDelta1>::validate(const Snapshot::Xml::PTimeDelta1::value_type& value_)
{
	QRegExp q("(-|\\+)?[0-9]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PTimeZone1

bool Validatable<Snapshot::Xml::PTimeZone1>::validate(const Snapshot::Xml::PTimeZone1::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9_\\.\\+\\-/]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PFilterParamName1

bool Validatable<Snapshot::Xml::PFilterParamName1>::validate(const Snapshot::Xml::PFilterParamName1::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9_]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PFilterParamValue1

bool Validatable<Snapshot::Xml::PFilterParamValue1>::validate(const Snapshot::Xml::PFilterParamValue1::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9_\\.:]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PSpaprvioReg1

bool Validatable<Snapshot::Xml::PSpaprvioReg1>::validate(const Snapshot::Xml::PSpaprvioReg1::value_type& value_)
{
	QRegExp q("(0x)?[0-9a-fA-F]{1,16}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PAliasName1

bool Validatable<Snapshot::Xml::PAliasName1>::validate(const Snapshot::Xml::PAliasName1::value_type& value_)
{
	QRegExp q("[a-zA-Z0-9_\\-.]+");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData1696

bool Validatable<Snapshot::Xml::PData1696>::validate(const Snapshot::Xml::PData1696::value_type& value_)
{
	QRegExp q("0x[0-9a-eA-E][0-9a-fA-F]?");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData1698

bool Validatable<Snapshot::Xml::PData1698>::validate(const Snapshot::Xml::PData1698::value_type& value_)
{
	QRegExp q("0x[fF][0-9a-eA-E]?");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData1700

bool Traits<Snapshot::Xml::PData1700>::parse(const QString& src_, Snapshot::Xml::PData1700::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PData1700>::generate(Snapshot::Xml::PData1700::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PData1700>::validate(Snapshot::Xml::PData1700::value_type value_)
{
	if (0 > value_)
		return false;

	if (254 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PCcwSsidRange1

bool Validatable<Snapshot::Xml::PCcwSsidRange1>::validate(const Snapshot::Xml::PCcwSsidRange1::value_type& value_)
{
	QRegExp q("(0x)?[0-3]");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData1702

bool Validatable<Snapshot::Xml::PData1702>::validate(const Snapshot::Xml::PData1702::value_type& value_)
{
	QRegExp q("0x[0-9a-fA-F]{1,4}");
	if (!q.exactMatch(value_))
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct PData1704

bool Traits<Snapshot::Xml::PData1704>::parse(const QString& src_, Snapshot::Xml::PData1704::value_type& dst_)
{
	bool output = false;
	dst_ = src_.toInt(&output);
	return output;
}

QString Traits<Snapshot::Xml::PData1704>::generate(Snapshot::Xml::PData1704::value_type src_)
{
	return QString::number(src_);
}

bool Validatable<Snapshot::Xml::PData1704>::validate(Snapshot::Xml::PData1704::value_type value_)
{
	if (0 > value_)
		return false;

	if (65535 < value_)
		return false;

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// struct VName

bool Traits<Snapshot::Xml::VName>::parse(const QString& src_, Snapshot::Xml::VName& dst_)
{
	int x;
	mpl::at_c<Snapshot::Xml::VName::types, 0>::type a0;
	x = Marshal<Snapshot::Xml::PDiskTarget1>::setString(src_, a0);
	if (0 < x)
	{
		dst_ = a0;
		return true;
	}
	mpl::at_c<Snapshot::Xml::VName::types, 1>::type a1;
	x = Marshal<Snapshot::Xml::PAbsFilePath1>::setString(src_, a1);
	if (0 < x)
	{
		dst_ = a1;
		return true;
	}

	return false;
}

QString Traits<Snapshot::Xml::VName>::generate(const Snapshot::Xml::VName& src_)
{
	switch (src_.which())
	{
	case 0:
		return Marshal<Snapshot::Xml::PDiskTarget1>::getString(boost::get<mpl::at_c<Snapshot::Xml::VName::types, 0>::type>(src_));
	case 1:
		return Marshal<Snapshot::Xml::PAbsFilePath1>::getString(boost::get<mpl::at_c<Snapshot::Xml::VName::types, 1>::type>(src_));
	}
	return QString();
}

///////////////////////////////////////////////////////////////////////////////
// struct VIpAddr

bool Traits<Snapshot::Xml::VIpAddr>::parse(const QString& src_, Snapshot::Xml::VIpAddr& dst_)
{
	int x;
	mpl::at_c<Snapshot::Xml::VIpAddr::types, 0>::type a0;
	x = Marshal<Snapshot::Xml::PIpv4Addr1>::setString(src_, a0);
	if (0 < x)
	{
		dst_ = a0;
		return true;
	}
	mpl::at_c<Snapshot::Xml::VIpAddr::types, 1>::type a1;
	x = Marshal<Snapshot::Xml::PIpv6Addr1>::setString(src_, a1);
	if (0 < x)
	{
		dst_ = a1;
		return true;
	}

	return false;
}

QString Traits<Snapshot::Xml::VIpAddr>::generate(const Snapshot::Xml::VIpAddr& src_)
{
	switch (src_.which())
	{
	case 0:
		return Marshal<Snapshot::Xml::PIpv4Addr1>::getString(boost::get<mpl::at_c<Snapshot::Xml::VIpAddr::types, 0>::type>(src_));
	case 1:
		return Marshal<Snapshot::Xml::PIpv6Addr1>::getString(boost::get<mpl::at_c<Snapshot::Xml::VIpAddr::types, 1>::type>(src_));
	}
	return QString();
}

///////////////////////////////////////////////////////////////////////////////
// struct VName1

bool Traits<Snapshot::Xml::VName1>::parse(const QString& src_, Snapshot::Xml::VName1& dst_)
{
	int x;
	mpl::at_c<Snapshot::Xml::VName1::types, 0>::type a0;
	x = Marshal<Snapshot::Xml::PDnsName1>::setString(src_, a0);
	if (0 < x)
	{
		dst_ = a0;
		return true;
	}
	mpl::at_c<Snapshot::Xml::VName1::types, 1>::type a1;
	x = Marshal<Snapshot::Xml::VIpAddr>::setString(src_, a1);
	if (0 < x)
	{
		dst_ = a1;
		return true;
	}

	return false;
}

QString Traits<Snapshot::Xml::VName1>::generate(const Snapshot::Xml::VName1& src_)
{
	switch (src_.which())
	{
	case 0:
		return Marshal<Snapshot::Xml::PDnsName1>::getString(boost::get<mpl::at_c<Snapshot::Xml::VName1::types, 0>::type>(src_));
	case 1:
		return Marshal<Snapshot::Xml::VIpAddr>::getString(boost::get<mpl::at_c<Snapshot::Xml::VName1::types, 1>::type>(src_));
	}
	return QString();
}

///////////////////////////////////////////////////////////////////////////////
// struct VUUID

bool Traits<Snapshot::Xml::VUUID>::parse(const QString& src_, Snapshot::Xml::VUUID& dst_)
{
	int x;
	mpl::at_c<Snapshot::Xml::VUUID::types, 0>::type a0;
	x = Marshal<Snapshot::Xml::PData1499>::setString(src_, a0);
	if (0 < x)
	{
		dst_ = a0;
		return true;
	}
	mpl::at_c<Snapshot::Xml::VUUID::types, 1>::type a1;
	x = Marshal<Snapshot::Xml::PData1501>::setString(src_, a1);
	if (0 < x)
	{
		dst_ = a1;
		return true;
	}

	return false;
}

QString Traits<Snapshot::Xml::VUUID>::generate(const Snapshot::Xml::VUUID& src_)
{
	switch (src_.which())
	{
	case 0:
		return Marshal<Snapshot::Xml::PData1499>::getString(boost::get<mpl::at_c<Snapshot::Xml::VUUID::types, 0>::type>(src_));
	case 1:
		return Marshal<Snapshot::Xml::PData1501>::getString(boost::get<mpl::at_c<Snapshot::Xml::VUUID::types, 1>::type>(src_));
	}
	return QString();
}

} // namespace Libvirt
