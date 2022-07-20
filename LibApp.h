//******************************************************************//
//                                                                  //
// NAME       : DEV JIGISHKUMAR SHAH                                // 
// STUDENT ID : 131623217                                           //
// MAIL ID    : djshah11@myseneca.ca                                //
// COURSE     : OOP 244 NCC                                         //
// SUBMISSION : SENECA LIBRARY APPLICATION (MILESTONE 2)            //
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

#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H

#include"Menu.h"

namespace sdds
{

	// CLASS.
	class LibApp
	{

		// DATA MEMBERS.
		bool m_changed;
		Menu m_mainMenu{ "Seneca Library Application" };
		Menu m_exitMenu{"Changes have been made to the data, what would you like to do?"};

		// MEMBER FUNCTION.
		void setEmpty();
		bool confirm(const char* message);
		void load();
		void save();
		void search();
		void returnPub();
		void newPublication();
		void removePublication();
		void checkOutPub();

	public:

		// CONSTRUCTOR.
		LibApp();

		// MEMBER FUNCTION.
		void run();

	};

}

#endif // !SDDS_LIBAPP_H
