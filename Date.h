	// Final Project Milestone 1
// Date Module
// File  Date.h
// Version 1.0
// Author   Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

#ifndef SDDS_DATE_H__
#define SDDS_DATE_H__

#include <iostream>

using namespace std;

namespace sdds
{

	// VARIABLE DECLARATION.
	const int NO_ERROR = 0;
	const int CIN_FAILED = 1;
	const int YEAR_ERROR = 2;
	const int MON_ERROR = 3;
	const int  DAY_ERROR = 4;
	const char DATE_ERROR[5][16] = {
	   "No Error",
	   "cin Failed",
	   "Bad Year Value",
	   "Bad Month Value",
	   "Bad Day Value"
	};
	const int  MIN_YEAR = 1500;

	// CLASS.
	class Date
	{

	private:

		// DATA MEMBERS.
		int m_year;
		int m_mon;
		int m_day;
		int m_errorCode;
		int m_currentYear;

		// PRIVATE MEMBER FUNCTIONS.
		void setEmpty();
		int daysSince0001_1_1() const;
		bool validate();
		void errCode(int);
		int systemYear() const;
		bool bad()const;
		int mdays()const;
		void setToToday();

	public:

		// CONSTRUCTORS.
		Date();
		Date(int year, int mon, int day);

		// PUBLIC MEMBER FUNCTIONS.
		int errCode()const;
		const char* dateStatus()const;
		int currentYear()const;
		istream& read(istream& is);
		ostream& write(ostream& os)const;

		// MEMBER OPERATORS.
		bool operator ==(Date& RO);
		bool operator !=(Date& RO);
		bool operator >=(Date& RO);
		bool operator <=(Date& RO);
		bool operator <(Date& RO);
		bool operator >(Date& RO);
		int operator -(Date& RO);
		operator bool();

	};

	// HELPER OPERATORS.
	ostream& operator<<(ostream& os, const Date& RO);
	istream& operator>>(istream& is, Date& RO);

}

#endif