/////////////////////////////////////////////////////////////////////////////
///
///	@file PrlVmUptimeTest.h
///
///	This file is the part of Virtuozzo public SDK library tests suite.
///	Tests fixture class for testing VM uptime feature.
///
///	@author sandro
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
/////////////////////////////////////////////////////////////////////////////

#ifndef PrlVmUptimeTest_H
#define PrlVmUptimeTest_H

#include <QtTest/QtTest>

class PrlVmUptimeTest : public QObject
{

Q_OBJECT

private slots:
	void testGetVmUptimeForCreateVm();
	void testGetVmUptimeForRegisterVm();
	void testGetVmUptimeUpdatingDuringVmWork();
	void testGetVmUptimeAccumulatingFromStartToStart();
	void testGetVmUptimeOnWrongParams();
	void testCantToChangeVmUptimeWithVmEditAction();
	void testResetVmUptime();
	void testResetVmUptimeForRunningVm();
	void testResetVmUptimeForVmClone();
	void testResetVmUptimeOnWrongParams();
	void testNewVmUptimeFunctionalityDoesntBrokeOldOne();
};

#endif

