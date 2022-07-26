#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H

#include<iostream>
#include"Lib.h"
#include"Date.h"

namespace sdds
{

	// CLASS.
	class Publication
	{

		// DATA MEMBER.
		// HOLDS THE TITLE OF THE PUBLICATION.
		char* m_title;
		// HOLDS THE SHELDID IN WHICH THE PUBLICATION IS STORED.
		char m_shelfID[SDDS_SHELF_ID_LEN + 1];
		// "m_membership" HOLDS THE MEMBERSHIP ID OF THE MEMBER WHO ISSUED THIS PUBLICATION. // "m_libRef" HOLDS A UNIQUE ID WHICH IDENTIFIES THIS PUBLICATION.
		int m_membership, m_libRef;
		// HOLDS THE DATE ON WHICH THE PUBLICATION WAS ISSUED.
		Date m_date;

		// CONSTRUCTOR.
		Publication();
		Publication(const Publication& source);

		// DESTRUCTOR.
		~Publication();

		// OPERATOR.
		bool operator==(const char* title)const;
		Publication& operator=(const Publication& source);

		// TYPE CASTING.
		operator const char* ()const;
		operator bool()const;

		// METHOD.
		void setEmpty();
		virtual void set(int member_id=0);
		void setRef(int value);
		void resetDate();
		virtual char type()const;
		bool onLoan()const;
		Date checkoutDate()const;
		int getRef()const;
		bool conIO(ios& io)const;
		ostream& write(ostream& os)const;
		istream& read(istream& istr);

	};

}

#endif // !SDDS_PUBLICATION_H
