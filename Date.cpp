// Final Project Milestone 1
// Date Module
// File  Date.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS

#include <iomanip>
#include <iostream>
#include <ctime>
#include "Date.h"

using namespace std;

namespace sdds
{

	// THE FOLLOWING GLOBAL VARIABLES ARE JUST FOR THE TESTING PURPOSE.
	bool sdds_test = false;
	int sdds_year = 2022;
	int sdds_mon = 8;
	int sdds_day = 7;

	// THIS WILL SET THE OBJECT TO EMPTY STATE.
	void Date::setEmpty()
	{

		m_year = 0;
		m_mon = 0;
		m_day = 0;
		m_errorCode = 0;
		m_currentYear = systemYear();

	}

	// THIS WILL RETURN TOTAL NUMBER OF DAYS SINCE 0001 / 01 / 01.
	int Date::daysSince0001_1_1()const
	{

		// VARIABLE DECLARATION.
		int ty = m_year;
		int tm = m_mon;

		if (tm < 3)
		{

			ty--;
			tm += 12;

		}

		return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 + m_day - 306;

	}

	// THIS WILL RETURN TRUE IF (YEAR, MONTH, AND DAY) IS IN PROPER RANGE. OTHERWISE, FALSE.
	bool Date::validate()
	{

		errCode(NO_ERROR);

		if (m_year < MIN_YEAR || m_year > m_currentYear + 1)
		{

			errCode(YEAR_ERROR);

		}
		else if (m_mon < 1 || m_mon > 12)
		{

			errCode(MON_ERROR);

		}
		else if (m_day < 1 || m_day > mdays())
		{

			errCode(DAY_ERROR);

		}

		return !bad();

	}

	// THIS WILL ASSIGN DATA MEMBER 'm_errorCode' A VALUE AS PER THE ERROR.
	void Date::errCode(int readErrorCode)
	{

		m_errorCode = readErrorCode;

	}

	int Date::systemYear()const
	{

		// VARIABLE DECLARATION.
		int theYear = sdds_year;

		if (!sdds_test)
		{

			// VARIABLE DECLARATION.
			time_t t = time(NULL);
			tm lt = *localtime(&t);

			theYear = lt.tm_year + 1900;

		}

		return theYear;

	}

	// THIS WILL RETURN TRUE IF THERE IS NO ERROR IN THE DATES. OTHERWISE FALSE.
	bool Date::bad()const
	{

		return m_errorCode != 0;

	}

	// THIS WILL RETURN THE NUMBER OF DAYS IN THE CURRENT MONTH.
	int Date::mdays()const
	{

		// VARIABLE DECLARATION.
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;

		mon--;

		return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));

	}

	// THIS WILL ASSIGN THE DATA MEMBERS VALUE AS PER CURRENT DATE.
	void Date::setToToday()
	{

		if (sdds_test)
		{

			m_day = sdds_day;
			m_mon = sdds_mon;
			m_year = sdds_year;

		}
		else
		{

			// VARIABLE DECLARATION.
			time_t t = time(NULL);
			tm lt = *localtime(&t);

			m_day = lt.tm_mday;
			m_mon = lt.tm_mon + 1;
			m_year = lt.tm_year + 1900;

		}

		errCode(NO_ERROR);

	}

	// THIS WILL BUILD AN OBJECT AND ASSIGN THE DATA MEMBERS VALUE AS PER CURRENT DATE.
	Date::Date() :m_currentYear(systemYear())
	{

		setToToday();

	}

	// THIS WILL BUILD AN OBJECT AND ASSIGN THE DATA MEMBERS VALUE AS PER THE RECEIVED ARGUMENT.
	Date::Date(int year, int mon, int day) : m_currentYear(systemYear())
	{

		// VARIABLE DECLARATION.
		m_year = year;
		m_mon = mon;
		m_day = day;

		validate();

	}

	// THIS WILL RETURN CURRENT ERROR CODE.
	int Date::errCode()const
	{

		return m_errorCode;

	}

	// THIS WILL RETURN THE DESCRIPTION OF THE ERROR ON THE BASIS OF ITS CODE.
	const char* Date::dateStatus()const
	{

		return DATE_ERROR[errCode()];

	}

	// THIS WILL RETURN THE VALUE OF DATA MEMBER 'm_currentYear'.
	int Date::currentYear()const
	{

		return m_currentYear;

	}

	istream& Date::read(istream& is)
	{

		// SETTING THE ERROR CODE TO 0.
		errCode(NO_ERROR);

		is >> m_year;
		is.ignore(1);
		is >> m_mon;
		is.ignore(1);
		is >> m_day;

		if (is.fail())
		{

			errCode(CIN_FAILED);
			is.clear();

		}
		else
		{

			validate();

		}

		return is;

	}

	ostream& Date::write(ostream& os = cout)const
	{

		// IF THE DATE VALUES ARE INVALID, THIS WILL PRINT THE DESCRIPTION OF THE ERROR.  
		if (bad())
		{

			os << dateStatus();

		}
		else
		{

			os << m_year << "/" << setw(2) << setfill('0') << right << m_mon << "/" << setw(2) << setfill('0') << right << m_day << setfill(' ');

		}

		return os;

	}

	bool Date::operator==(const Date& RO)const
	{

		return (daysSince0001_1_1() == RO.daysSince0001_1_1());

	}

	bool Date::operator!=(const Date& RO)const
	{

		return !(*this == RO);

	}

	bool Date::operator>=(const Date& RO)const
	{

		return(*this > RO || *this == RO);

	}

	bool Date::operator<=(const Date& RO)const
	{

		return(*this < RO || *this == RO);

	}

	bool Date::operator<(const Date& RO)const
	{

		return (daysSince0001_1_1() < RO.daysSince0001_1_1());

	}

	bool Date::operator>(const Date& RO)const
	{

		return (!(*this < RO) && (*this != RO));

	}

	int Date::operator-(const Date& RO)const
	{

		return daysSince0001_1_1() - RO.daysSince0001_1_1();

	}

	Date& Date::operator=(const Date& source)
	{

		if (this != &source)
		{

			m_year = source.m_year;
			m_mon = source.m_mon;
			m_day = source.m_day;
			m_errorCode = source.m_errorCode;
			m_currentYear = source.m_currentYear;

		}

		return *this;

	}

	Date::operator bool()const
	{

		return !bad();

	}

	ostream& operator<<(ostream& os, const Date& RO)
	{

		return RO.write(os);

	}

	istream& operator>>(istream& is, Date& RO)
	{

		return RO.read(is);

	}

}