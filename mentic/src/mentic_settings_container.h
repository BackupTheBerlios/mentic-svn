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

#include <qdialog.h>
 
#ifndef MENTIC_SETTINGS_CONTAINER
#define MENTIC_SETTINGS_CONTAINER

class QSettings;

///Contains all application settings
///and manages saving and loading of them.
class MenticSettingsContainer
{
public:
	~MenticSettingsContainer();
	static MenticSettingsContainer* get() { _instance ? _instance : _instance = new MenticSettingsContainer(); return _instance; }
	static void save() { delete _instance; _instance = 0; }
	
	bool addition;
	bool substraction;
	bool multiplication;
	bool division;
private:
	MenticSettingsContainer();
	
	QSettings* m_settings;
	static MenticSettingsContainer* _instance;
};

typedef MenticSettingsContainer MSC;

#endif

