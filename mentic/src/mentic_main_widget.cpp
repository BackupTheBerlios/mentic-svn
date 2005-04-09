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
#include <qlineedit.h>
#include <qlabel.h>
#include <qvalidator.h>
#include <qpushbutton.h>
#include <qapplication.h>
 
#include "mentic_main_widget.h"
#include "mentic_options_dialog.h"

MenticMainWidget::MenticMainWidget()
{
	right_results = 0;
	wrong_results = 0;

	setCaption("Mentic " + tr("Mental arithmetic trainer"));
	QGridLayout* grid = new QGridLayout(this);
	grid->setMargin(5);
	grid->setSpacing(5);
	
	order = new QLabel(tr("Calculate the following term!"),this);
	term = new QLabel(this);
	term->setFrameStyle( QFrame::Box | QFrame::Plain );
	term->setAlignment(Qt::AlignHCenter);
	stat = new QLabel(this);
	stat->setFrameStyle( QFrame::GroupBoxPanel | QFrame::Sunken );
	mental_result = new QLineEdit(this);
	mental_result->setValidator(new QDoubleValidator(this));
	QPushButton* check_result = new QPushButton(tr("Check"),this);
	
	connect(mental_result,SIGNAL(returnPressed()),this,SLOT(checkResult()));
	connect(check_result,SIGNAL(clicked()),this,SLOT(checkResult()));
	
	QPushButton* quit = new QPushButton(tr("Quit"),this);
	QPushButton* options = new QPushButton(tr("Options"),this);
	
	connect(quit,SIGNAL(clicked()),qApp,SLOT(quit()));
	connect(options,SIGNAL(clicked()),this,SLOT(optionsDialog()));
	
	grid->addMultiCellWidget(order,0,0,0,1);
	grid->addMultiCellWidget(term,1,1,0,1);
	grid->addWidget(mental_result,2,0);
	grid->addWidget(check_result,2,1);
	grid->addMultiCellWidget(stat,3,3,0,1);
	grid->addWidget(quit,4,0);
	grid->addWidget(options,4,1);
	
	newTerm();
}

void MenticMainWidget::newTerm()
{
	operands.clear();
	operators.clear();
	
	operands.push_back(int(rand()) % 101);
	switch(rand() % 4)
	{
		case 0:
			operators.push_back('+');
			break;
		case 1:
			operators.push_back('-');
			break;
		case 2:
			operators.push_back('/');
			break;
		case 3:
			operators.push_back('*');
			break;
		default:
			break;
	}
	if((*operators.rbegin()) != '/')
		operands.push_back(int(rand()) % 101);
	else
	{
		double myop = (*operands.rbegin());
		if((int(rand())%2))
			operands.push_back(myop * (int(rand()) % 11));
		else
			operands.push_back(0);
			
		if((*operands.rbegin()) == 0)
			(*operands.rbegin()) = 1;
	}
	
	QString tmp;
	std::vector<char>::iterator cit = operators.begin();
	for(std::vector<double>::iterator it = operands.begin(); it != operands.end(); ++cit)
	{
		tmp += QString::number((*it));
		++it;
		if(it == operands.end() || cit == operators.end())
			break;
		tmp += " " + QString(QChar((*cit))) + " ";
	}
	term->setText(tmp);
	mental_result->clear();
}

void MenticMainWidget::checkResult()
{
	double result = 0;
	std::vector<char>::iterator cit = operators.begin();
	for(std::vector<double>::iterator it = operands.begin(); it != operands.end(); ++cit)
	{
		if(it == operands.begin())
		{
			result = (*it);
			++it;
		}
		if(it == operands.end() || cit == operators.end())
			break;
		switch((*cit))
		{
			case '+':
				result += (*it);
				break;
			case '-':
				result -= (*it);
				break;
			case '/':
				result /= (*it);
				break;
			case '*':
				result *= (*it);
				break;
			default:
				break;	
		}
	}
	
	if(result == mental_result->text().toDouble())
	{
		++right_results;
		stat->setText("Right! - Right results: " + QString::number(right_results) + " Wrong results: " + QString::number(wrong_results));
	}
	else
	{
		++wrong_results;
		stat->setText("Wrong! - Right results: " + QString::number(right_results) + " Wrong results: " + QString::number(wrong_results));
	}
	
	newTerm();
}

void MenticMainWidget::optionsDialog()
{
	MenticOptionsDialog* options = new MenticOptionsDialog();
	options->exec();
}



