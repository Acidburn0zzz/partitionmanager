/***************************************************************************
 *   Copyright (C) 2010 by Volker Lanz <vl@fidra.de>                       *
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
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA            *
 ***************************************************************************/

#if !defined(DEVICEPROPSWIDGET__H)

#define DEVICEPROPSWIDGET__H

#include "ui_devicepropswidgetbase.h"

class PartTableWidget;

/** @brief Central widget in the DevicePropsDialog.
	@author vl@fidra.de
*/
class DevicePropsWidget : public QWidget, public Ui::DevicePropsWidgetBase
{
	public:
		DevicePropsWidget(QWidget* parent) : QWidget(parent) { setupUi(this); }

	public:
		PartTableWidget& partTableWidget() { Q_ASSERT(m_PartTableWidget); return *m_PartTableWidget; }

		QLabel& chs() { Q_ASSERT(m_LabelCHS); return *m_LabelCHS; }
		QLabel& capacity() { Q_ASSERT(m_LabelCapacity); return *m_LabelCapacity; }
		QLabel& cylinderSize() { Q_ASSERT(m_LabelCylinderSize); return *m_LabelCylinderSize; }
		QLabel& primariesMax() { Q_ASSERT(m_LabelPrimariesMax); return *m_LabelPrimariesMax; }
		QLabel& sectorSize() { Q_ASSERT(m_LabelSectorSize); return *m_LabelSectorSize; }
		QLabel& totalSectors() { Q_ASSERT(m_LabelTotalSectors); return *m_LabelTotalSectors; }
		QLabel& type() { Q_ASSERT(m_LabelType); return *m_LabelType; }

		QRadioButton& radioCylinderBased() { Q_ASSERT(m_RadioCylinderBased); return *m_RadioCylinderBased; }
		const QRadioButton& radioCylinderBased() const { Q_ASSERT(m_RadioCylinderBased); return *m_RadioCylinderBased; }

		QRadioButton& radioSectorBased() { Q_ASSERT(m_RadioSectorBased); return *m_RadioSectorBased; }
		const QRadioButton& radioSectorBased() const { Q_ASSERT(m_RadioSectorBased); return *m_RadioSectorBased; }

		QSpacerItem& spacerType() { Q_ASSERT(m_SpacerType); return *m_SpacerType; }

		void hideTypeRadioButtons()
		{
			radioSectorBased().setVisible(false);
			radioCylinderBased().setVisible(false);
		}

		QLabel& smartStatus() { Q_ASSERT(m_LabelSmartStatus); return *m_LabelSmartStatus; }
		QLabel& temperature() { Q_ASSERT(m_LabelSmartTemperature); return *m_LabelSmartTemperature; }
		QLabel& badSectors() { Q_ASSERT(m_LabelSmartBadSectors); return *m_LabelSmartBadSectors; }
		QLabel& poweredOn() { Q_ASSERT(m_LabelSmartPoweredOn); return *m_LabelSmartPoweredOn; }
		QLabel& powerCycles() { Q_ASSERT(m_LabelSmartPowerCycles); return *m_LabelSmartPowerCycles; }

		QLabel& labelTemperature() { Q_ASSERT(m_LabelTextSmartTemperature); return *m_LabelTextSmartTemperature; }
		QLabel& labelBadSectors() { Q_ASSERT(m_LabelTextSmartBadSectors); return *m_LabelTextSmartBadSectors; }
		QLabel& labelPoweredOn() { Q_ASSERT(m_LabelTextSmartPoweredOn); return *m_LabelTextSmartPoweredOn; }
		QLabel& labelPowerCycles() { Q_ASSERT(m_LabelTextSmartPowerCycles); return *m_LabelTextSmartPowerCycles; }

		void hideSmartLabels()
		{
			temperature().setVisible(false);
			badSectors().setVisible(false);
			poweredOn().setVisible(false);
			powerCycles().setVisible(false);

			labelTemperature().setVisible(false);
			labelBadSectors().setVisible(false);
			labelPoweredOn().setVisible(false);
			labelPowerCycles().setVisible(false);
		}
};

#endif
