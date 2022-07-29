//******************************************************************//
//                                                                  //
// NAME       : DEV JIGISHKUMAR SHAH                                // 
// STUDENT ID : 131623217                                           //
// MAIL ID    : djshah11@myseneca.ca                                //
// COURSE     : OOP 244 NCC                                         //
// SUBMISSION : MILESTONE 3                                         //
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

		delete[]m_title;

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

			delete[]m_title;
			setDefault();

			strcpy(m_title, source.m_title);
			strcpy(m_shelfID, source.m_shelfID);
			m_membership = source.m_membership;
			m_libRef = source.m_libRef;
			m_date = source.m_date;

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

		m_membership = member_id;

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

	bool Publication::conIO(std::ios& io)const
	{

		return (&io == &cout || &io == &cin);

	}

	ostream& Publication::write(std::ostream& out)const
	{

		if (conIO(out))
		{

			out << "| " << m_shelfID << " | " << setw(30) << setfill('.') << left << m_title << " | " << m_membership << " | " << m_date << " |";

		}
		else
		{

			out << type() << "\t" << m_shelfID << "\t" << m_title << "\t" << m_membership << "\t" << m_date;

		}

		return out;

	}

	istream& Publication::read(istream& in)
	{

		// VARIABLE DECLARATION.
		char whatsTitle[255 + 1];
		char whichShelf[SDDS_SHELF_ID_LEN + 1];
		unsigned int whichMember = 0;
		int whatsrefNum = -1;
		Date whichDate;

		delete[] m_title;
		setDefault();

		if (conIO(in))
		{

			cout << "Shelf No: ";
			in.getline(whichShelf, 4, '\n');

			if (strlen(whichShelf) != 4)
			{

				/////////////////////////////

			}

			cout << "Title: ";

			in.getline(whatsTitle, 255, '\n');

			cout << "Date: ";
			in >> m_date;

		}
		else
		{

			in.ignore(1, '\t');
			in >> whatsrefNum;
			in.ignore(1, '\t');
			in.getline(whichShelf, 4, '\t');
			in.getline(whatsTitle, 255, '\t');
			in >> m_membership;
			in.ignore(1, '\t');
			in >> m_date;

		}

		if (m_date)
		{

			//////////////////////////////////////////////////////////////////////////////////////////////////

		}

		if (in)
		{

			delete[] m_title;
			setTitle(whatsTitle);
			strcpy(m_shelfID, whichShelf);
			set(whichMember);
			m_date = whichDate;
			setRef(whatsrefNum);

		}

		return in;

	}

}