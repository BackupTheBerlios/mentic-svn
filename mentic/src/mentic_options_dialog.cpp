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

#include <qlayout.h>
#include <qpushbutton.h>
#include <qcheckbox.h>

#include "mentic_options_dialog.h"
#include "mentic_settings_container.h"

MenticOptionsDialog::MenticOptionsDialog()
{
	setCaption("Mentic Settings");

	QGridLayout* grid = new QGridLayout(this);

	addition = new QCheckBox(tr("Addition"),this);
	if(MSC::get()->addition)
		addition->setChecked(true);
	substraction = new QCheckBox(tr("Substraction"),this);
	if(MSC::get()->substraction)
		substraction->setChecked(true);
	multiplication = new QCheckBox(tr("Multiplication"),this);
	if(MSC::get()->multiplication)
		multiplication->setChecked(true);
	division = new QCheckBox(tr("Division"),this);
	if(MSC::get()->division)
		division->setChecked(true);

	QPushButton* ok = new QPushButton(tr("Ok"),this);
	QPushButton* cancel = new QPushButton(tr("Cancel"),this);

	connect(ok,SIGNAL(clicked()),this,SLOT(accept()));
	connect(cancel,SIGNAL(clicked()),this,SLOT(reject()));

	grid->addWidget(addition,0,0);
	grid->addWidget(substraction,1,0);
	grid->addWidget(multiplication,2,0);
	grid->addWidget(division,3,0);
	grid->addWidget(ok,4,0);
	grid->addWidget(cancel,4,1);
}

void MenticOptionsDialog::accept()
{
	MSC::get()->addition = addition->isChecked();
	MSC::get()->substraction = substraction->isChecked();
	MSC::get()->multiplication = multiplication->isChecked();
	MSC::get()->division = division->isChecked();

	QDialog::accept();
}



