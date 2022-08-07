//******************************************************************//
//                                                                  //
// NAME       : DEV JIGISHKUMAR SHAH                                // 
// STUDENT ID : 131623217                                           //
// MAIL ID    : djshah11@myseneca.ca                                //
// COURSE     : OOP 244 NCC                                         //
// SUBMISSION : SENECA LIBRARY APPLICATION (MILESTONE 3)            //
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

#include<iostream>
#include<cstring>
#include"Publication.h"
#include <iomanip>
#include"Utils.h"

using namespace std;

namespace sdds
{

	void Publication::setDefault()
	{

		m_title = nullptr;
		m_shelfID[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		m_date = Date();

	}

	void Publication::setTitle(const char* title)
	{

		m_title = new char[255 + 1];
		strcpy(m_title, title);

	}

	// CONSTRUCTOR.
	Publication::Publication()
	{

		setDefault();

	}

	Publication::Publication(const Publication& source)
	{

		setDefault();

		if (bool(source))
		{

			*this = source;

		}

	}

	// DESTRUCTOR.
	Publication::~Publication()
	{

		delete[] m_title;

	}

	// OPERATOR.
	bool Publication::operator==(const char* title)const
	{

		return strstr(m_title, title);

	}

	Publication& Publication::operator=(const Publication& source)
	{

		if (this != &source)
		{

			delete[] m_title;
			setDefault();

			if (bool(source))
			{

				setTitle(source.m_title);
				strcpy(m_shelfID, source.m_shelfID);
				set(source.m_membership);
				setRef(source.m_libRef);
				m_date = source.m_date;

			}

		}

		return *this;

	}

	// TYPE CASTING.
	Publication::operator const char* ()const
	{

		return m_title;

	}

	Publication::operator bool()const
	{

		return(m_title != nullptr && m_shelfID[0] != '\0');

	}

	// METHOD.
	void Publication::set(int member_id)
	{

		if (member_id < 100000)
		{

			m_membership = member_id;

		}

	}

	void Publication::setRef(int value)
	{

		m_libRef = value;

	}

	void Publication::resetDate()
	{

		m_date = Date();

	}

	char Publication::type()const
	{

		return 'P';

	}

	bool Publication::onLoan()const
	{

		return (m_membership != 0);

	}

	Date Publication::checkoutDate()const
	{

		return m_date;

	}

	int Publication::getRef()const
	{

		return m_libRef;

	}

	bool Publication::conIO(ios& io)const
	{

		return (&io == &cout || &io == &cin);

	}

	ostream& Publication::write(ostream& out)const
	{

		if (conIO(out))
		{

			if (strlen(m_title) >= 30)
			{

				out << "| " << setw(4) << m_shelfID << " | ";

				onlyPrint(m_title, 30, out);

				out << " | ";

			}
			else
			{

				out << "| " << setw(4) << m_shelfID << " | " << setw(30) << setfill('.') << left << m_title << " | ";

			}

			whichMember(m_membership, out);

			out << " | " << m_date << " |";

		}
		else
		{

			out << type() << "\t" << m_libRef << "\t" << m_shelfID << "\t" << m_title << "\t" << m_membership << "\t" << m_date;

		}

		return out;

	}

	istream& Publication::read(istream& in)
	{

		// VARIABLE DECLARATION.
		char t_title[255 + 1], t_shelfID[SDDS_SHELF_ID_LEN + 2];
		int t_membership = 0, t_libRef = -1;
		Date t_date;

		if (conIO(in))
		{

			cout << "Shelf No: ";
			in.get(t_shelfID, SDDS_SHELF_ID_LEN + 2, '\n');

			if (strlen(t_shelfID) != 4)
			{

				in.setstate(ios::failbit);

			}

			in.ignore(1000, '\n');

			cout << "Title: ";
			in.get(t_title, 255 + 1, '\n');
			in.ignore(1000, '\n');

			cout << "Date: ";
			in >> t_date;

		}
		else
		{

			in >> t_libRef;
			in.ignore(100, '\t');

			in.getline(t_shelfID, SDDS_SHELF_ID_LEN + 1, '\t');

			in.getline(t_title, 255 + 1, '\t');

			in >> t_membership;

			in.ignore(100, '\t');

			in >> t_date;

		}

		if (!t_date)
		{

			in.setstate(ios::failbit);

		}

		if (in)
		{

			delete[] m_title;
			setDefault();

			setTitle(t_title);
			strcpy(m_shelfID, t_shelfID);
			set(t_membership);
			m_date = t_date;
			setRef(t_libRef);

		}

		return in;

	}

	ostream& Publication::whichMember(int f_membership, ostream& out)const
	{

		if (!f_membership)
		{

			out << setw(5) << " N/A ";

		}
		else
		{

			out << setw(5) << f_membership;

		}

		return out;

	}

}