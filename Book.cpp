//******************************************************************//
//                                                                  //
// NAME       : DEV JIGISHKUMAR SHAH                                // 
// STUDENT ID : 131623217                                           //
// MAIL ID    : djshah11@myseneca.ca                                //
// COURSE     : OOP 244 NCC                                         //
// SUBMISSION : SENECA LIBRARY APPLICATION (MILESTONE 4)            //
//                                                                  //
//******************************************************************// 
//                                                                  //
// AUTHENTICITY DECLARATION :                                       //
// I DECLARE THAT THIS SUBMISSION IS THE RESULT OF MY OWN WORK AND  //
// HAS NOT BEEN SHARED WITH ANY OTHR STUDENT OR 3RD PARTY CONTENT   //
// PROVIDER. THIS SUBMITTED PIECE OF WORK IS ENTIRELY OF MY OWN     //
// CREATION.                                                        //
//                                                                  //
//******************************************************************//

#define _CRT_SECURE_NO_WARNINGS

#include"Book.h"
#include<cstring>
#include"Lib.h"
#include<iomanip>
#include"Utils.h"

namespace sdds
{

	// METHOD.
	void Book::setEmpty()
	{

		m_author = nullptr;

	}

	void Book::updateAuth(const char* f_author)
	{

		m_author = new char[strlen(f_author) + 1];
		strcpy(m_author, f_author);

	}

	void Book::assDataMembs(const Book& f_source)
	{

		delete[] m_author;
		setEmpty();
		updateAuth(f_source.m_author);

	}

	// CONSTRUCTOR.
	Book::Book()
	{

		setEmpty();

	}

	Book::Book(const Book& f_source) :Publication(f_source)
	{

		setEmpty();

		if (bool(f_source))
		{

			assDataMembs(f_source);

		}

	}

	// DESTRUCTOR.
	Book::~Book()
	{

		delete[] m_author;

	}

	// OPERATOR.
	Book& Book::operator=(const Book& f_source)
	{

		if (this != &f_source && bool(f_source))
		{

			Publication::operator=(f_source);

			delete[] m_author;
			setEmpty();
			assDataMembs(f_source);

		}

		return *this;

	}

	// TYPE CASTING.
	Book::operator bool()const
	{

		return (m_author != nullptr && Publication::operator bool());

	}

	// METHOD.
	char Book::type()const
	{

		return 'B';

	}

	ostream& Book::write(ostream& f_out)const
	{

		Publication::write(f_out);

		if (Publication::conIO(f_out))
		{

			if (strlen(m_author) >= SDDS_AUTHOR_WIDTH)
			{

				f_out << " ";

				onlyPrint(m_author, SDDS_AUTHOR_WIDTH, f_out);

				f_out << " |";

			}
			else
			{

				f_out << " " << setw(SDDS_AUTHOR_WIDTH) << left << m_author << " |";

			}

		}
		else
		{

			f_out << '\t' << m_author;

		}

		return f_out;

	}

	istream& Book::read(istream& f_in)
	{

		// VARIABLE DECLARATION.
		char t_author[256 + 1];

		Publication::read(f_in);

		delete[] m_author;
		setEmpty();

		if (Publication::conIO(f_in))
		{

			f_in.ignore(1, '\n');
			cout << "Author: ";
			f_in.get(t_author, 256, '\n');
			f_in.ignore(1000, '\n');

		}
		else
		{

			f_in.ignore(1000, '\t');
			f_in.get(t_author, 256, '\n');

		}

		if (f_in)
		{

			updateAuth(t_author);

		}

		return f_in;

	}

	void Book::set(int f_memberID)
	{

		Publication::set(f_memberID);
		Publication::resetDate();

	}

}