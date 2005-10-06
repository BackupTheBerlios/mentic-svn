/***************************************************************************
 *   Copyright (C) 2005 by Tobias Glaesser                                 *
 *   tobi.web@gmx.de                                                       *
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
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <qsettings.h>
#include <qdir.h>

#include "mentic_settings_container.h"

MenticSettingsContainer* MenticSettingsContainer::_instance = NULL;

MenticSettingsContainer::MenticSettingsContainer()
{
	m_settings = new QSettings(QSettings::Native);
	
	m_settings->insertSearchPath( QSettings::Unix, QDir::homeDirPath() + "/.mentic/");
	
	m_settings->beginGroup("config");
	
	m_settings->beginGroup("calctypes");
	addition = m_settings->readBoolEntry("addition",true);
	substraction = m_settings->readBoolEntry("substraction",true);
	multiplication = m_settings->readBoolEntry("multiplication",true);
	division = m_settings->readBoolEntry("division",true);
	m_settings->endGroup();
}

MenticSettingsContainer::~MenticSettingsContainer()
{
	m_settings->writeEntry("/calctypes/addition",addition);
	m_settings->writeEntry("/calctypes/substraction",substraction);
	m_settings->writeEntry("/calctypes/multiplication",multiplication);
	m_settings->writeEntry("/calctypes/division",division);

	m_settings->endGroup();
	delete m_settings;
}

