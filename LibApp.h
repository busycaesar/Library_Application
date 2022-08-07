//******************************************************************//
//                                                                  //
// NAME       : DEV JIGISHKUMAR SHAH                                //
// STUDENT ID : 131623217                                           //
// MAIL ID    : djshah11@myseneca.ca                                //
// COURSE     : OOP 244 NCC                                         //
// SUBMISSION : SENECA LIBRARY APPLICATION (MILESTONE 2)            //
//              SENECA LIBRARY APPLICATION (MILESTONE 5.1)          //
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
#include"Publication.h"

namespace sdds
{

	// CLASS.
	class LibApp
	{

		// DATA MEMBERS.
		bool m_changed;
		Menu m_mainMenu{ "Seneca Library Application" }, m_exitMenu{ "Changes have been made to the data, what would you like to do?" }, m_PubType{ "Choose the type of publication:" };
		char m_fileName[256 + 1]{};
		Publication* m_PPA[SDDS_LIBRARY_CAPACITY];
		int m_NOLPinPPA, m_LLRN;


		// MEMBER FUNCTION.
		void setEmpty();
		bool confirm(const char* message);
		void load();
		void save();
		int search(int f_whichopt);
		void returnPub();
		void newPublication();
		void removePublication();
		void checkOutPub();
		char whichType()const;
		void aborted()const;
		Publication* getPub(int libRef)const;

	public:

		// CONSTRUCTOR.
		LibApp(const char* f_fileName);

		// DESTRUCTOR.
		~LibApp();

		// MEMBER FUNCTION.
		void run();

	};

}

#endif // !SDDS_LIBAPP_H