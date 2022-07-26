#include<iostream>
#include<cstring>
#include"Publication.h"

using namespace std;

namespace sdds
{

	// CONSTRUCTOR.
	Publication::Publication()
	{

		setEmpty();

	}
	Publication::Publication(const Publication& source)
	{

		setEmpty();
		*this = source;

	}

	// DESTRUCTOR.
	Publication::~Publication()
	{

		delete[]m_title;
		m_title = nullptr;

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
			setEmpty();

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
	void Publication::setEmpty()
	{

		m_title = nullptr;
		m_title = new char[255];
		m_shelfID[0] = '\0';
		m_membership = 0;
		m_libRef = -1;

	}

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
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	}

	int Publication::getRef()const
	{

		return m_libRef;

	}

	bool Publication::conIO(ios& io)const
	{

		return (&io == &cout || &io == &cin);

	}

	ostream& Publication::write(ostream& os)const
	{

		if (conIO(os))
		{

			os << "| " << m_shelfID << " | ";
			os.width(30);
			os.fill('.');
			os << left << m_title << " | " << m_membership << " | " << m_date << " |";

		}
		else
		{

			os << type() << "	" << m_shelfID << "	" << m_title << "	" << m_membership << "	" << m_date;

		}

	}

	istream& Publication::read(istream& istr)//////////////////////////
	{

		delete[] m_title;
		setEmpty();

		if (conIO(istr))
		{

			cout << "Shelf No: ";
			istr.get(m_shelfID, SDDS_SHELF_ID_LEN);///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			cout << "Title: ";
			istr >> m_title;
			cout << "Date: ";
			istr >> m_date;

		}


	}

}