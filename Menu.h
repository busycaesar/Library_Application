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

#ifndef SDDS_MENU_H
#define SDDS_MENU_H

#include<iostream>
#include<cstring>

using namespace std;

namespace sdds
{

	// CONSTANTS.
	const int MAX_MENUITEMS = 20;

	// CLASS.
	class MenuItem
	{

		// DATA MEMBER.
		char* m_item;

		// CONSTRUCTOR.
		MenuItem();
		MenuItem(const char* item);
		MenuItem(const MenuItem& source) = delete;

		// DESTRUCTOR.
		~MenuItem();

		// MEMBER FUNCTIONS.
		void setEmpty();
		bool isEmpty()const;
		void setItem(const char* item);
		ostream& display(ostream& out)const;

		// TYPE CONVERSION.
		operator bool()const;
		operator const char* ()const;

		// OPERATOR.
		MenuItem& operator=(const MenuItem& source) = delete;

		// FRIEND.
		friend class Menu;

	};

	class Menu
	{

		// DATA MEMBERS.
		char* m_MenuTitle;
		MenuItem* m_items[MAX_MENUITEMS];
		unsigned int m_totalItems;

		// MEMBER FUNCTION.
		void setEmpty();

	public:

		// CONSTRUCTOR.
		Menu();
		Menu(const char* title);

		// DESTRUCTOR.
		~Menu();

		// MEMBER FUNCTION.
		ostream& displayTitle(ostream& out)const;
		ostream& displayMenu(ostream& out)const;
		unsigned int run()const	;

		// OPERATOR.
		unsigned int operator~()const;
		Menu& operator<<(const char* menuitemConent);
		const char* operator[](unsigned int i)const;

		// TYPE CONVERSION.
		operator int()const;
		operator unsigned int()const;
		operator bool()const;

	};

	ostream& operator<<(ostream& LO, Menu& RO);

}

#endif // !SDDS_MENU_H 
