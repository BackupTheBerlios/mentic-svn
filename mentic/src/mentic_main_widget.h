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

#include <vector>
 
#include <qwidget.h>

#ifndef MENTIC_MAIN_WIDGET
#define MENTIC_MAIN_WIDGET

class QLabel;
class QLineEdit;

class MenticMainWidget : public QWidget
{
	Q_OBJECT

	public:
	MenticMainWidget();
	
	private slots:
	void checkResult();
	void optionsDialog();
	
	private:
	void newTerm();
	
	QLabel* order;
	QLabel* term;
	QLabel* stat;
	QLineEdit* mental_result;
	
	std::vector<double> operands;
	std::vector<char> operators;
	
	unsigned int right_results;
	unsigned int wrong_results;
};

#endif

