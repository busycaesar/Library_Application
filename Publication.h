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

#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H

#include<iostream>
#include"Lib.h"
#include"Date.h"
#include"Streamable.h"

namespace sdds
{

	// CLASS.
	class Publication : public Streamable
	{

		// DATA MEMBER.
		// HOLDS THE TITLE OF THE PUBLICATION.
		char* m_title;
		// HOLDS THE SHELDID IN WHICH THE PUBLICATION IS STORED.
		char m_shelfID[SDDS_SHELF_ID_LEN + 1];
		// HOLDS THE MEMBERSHIP ID OF THE MEMBER WHO ISSUED THIS PUBLICATION.
		int m_membership;
		// HOLDS A UNIQUE ID WHICH IDENTIFIES THIS PUBLICATION.
		int m_libRef;
		// HOLDS THE DATE ON WHICH THE PERIODICAL PUBLICATION WAS ISSUED. || HOLDS THE DATE ON WHICH THE BOOK WAS BORROWED BY THE MEMBER.
		Date m_date;

		// METHOD.
		void setDefault();
		void setTitle(const char* title);

	public:

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
		virtual void set(int member_id);
		void setRef(int value);
		void resetDate();
		virtual char type()const;
		bool onLoan()const;
		Date checkoutDate()const;
		int getRef()const;
		virtual bool conIO(ios& io)const;
		virtual ostream& write(ostream& out)const;
		virtual istream& read(istream& in);
		ostream& whichMember(int f_membership, ostream& out)const;

	};

}

#endif // !SDDS_PUBLICATION_H
