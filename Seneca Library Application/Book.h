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

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include"Publication.h"

namespace sdds
{

	// CLASS.
	class Book : public Publication
	{

		// DATA MEMBER.
		char* m_author;

		// METHOD.
		void setEmpty();
		void updateAuth(const char* f_author);
		void assDataMembs(const Book& f_source);

	public:

		// CONSTRUCTOR.
		Book();
		Book(const Book& f_source);

		// DESTRUCTOR.
		~Book();

		// OPERATOR.
		Book& operator=(const Book& f_source);

		// TYPE CASTING.
		operator bool()const;

		// METHOD.
		virtual char type()const;
		virtual ostream& write(ostream& f_out)const;
		virtual istream& read(istream& f_in);
		virtual void set(int f_memberID);

	};

}

#endif // !SDDS_BOOK_H