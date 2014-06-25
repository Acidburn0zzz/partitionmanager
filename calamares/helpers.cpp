/***************************************************************************
 *   Copyright (C) 2008, 2009, 2010 by Volker Lanz <vl@fidra.de>           *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.          *
 ***************************************************************************/

// This version of helpers.cpp contains only the functions we need for
// libcalapm. This trims dependencies as the original helpers.cpp brings in
// KCoreAddons and KWidgetsAddons

#include <util/helpers.h>

#include <Solid/Device>

QList<Solid::Device> getSolidDeviceList()
{
#ifdef ENABLE_UDISKS2
        QString predicate = QStringLiteral("StorageVolume.usage == 'PartitionTable'");

#else
        QString predicate = "[ [ [ StorageDrive.driveType == 'HardDisk' OR StorageDrive.driveType == 'CompactFlash'] OR "
                "[ StorageDrive.driveType == 'MemoryStick' OR StorageDrive.driveType == 'SmartMedia'] ] OR "
                "[ StorageDrive.driveType == 'SdMmc' OR StorageDrive.driveType == 'Xd'] ]";
#endif

	QStringList argList;
	int argc = argList.size();
	if (argc > 0)
	{
		predicate = QStringLiteral(" [ ") + predicate + QStringLiteral(" AND ");

		qint32 brackets = (argc + 1) / 2;
		brackets = argc == 1 ? 0 : brackets;
		for (qint32 i = 0; i < brackets; i++)
			predicate += QStringLiteral("[ ");

		bool right_bracket = false;
		for (qint32 i = 0; i < argc; i++, right_bracket =! right_bracket)
		{
			predicate += QStringLiteral("Block.device == '%1' ").arg(argList[i]);

			if (right_bracket)
				predicate += i == 1 ? QStringLiteral("] ") : QStringLiteral("] ] ");
			if (i < argc - 1)
				predicate += QStringLiteral("OR ");
			if (right_bracket && i != argc - 2 && i != argc - 1)
				predicate += QStringLiteral("[ ");
		}
		predicate += right_bracket && brackets > 0 ? QStringLiteral("] ]") : QStringLiteral("]");
	}

	return Solid::Device::listFromQuery(predicate);
}
