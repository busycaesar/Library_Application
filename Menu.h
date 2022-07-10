#ifndef SDDS_MENU_H
#define SDDS_MENU_H

#include<iostream>

using namespace std;

namespace sdds
{

	// CONSTANTS.
	const int MAX_MENU_ITEMS = 20;

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
		bool isEmpty();
		ostream& display(ostream& out);

		// TYPE CONVERSION.
		operator bool();
		operator const char* ();

		// OPERATOR.
		MenuItem& operator=(const MenuItem& source) = delete;

		// FRIEND.
		friend class Menu;

	};

	class Menu
	{

		// DATA MEMBERS.
		char* m_MenuItem;
		MenuItem* m_items[MAX_MENU_ITEMS];
		int m_totalItems;

		// MEMBER FUNCTION.
		void setEmpty();

	public:

		// CONSTRUCTOR.
		Menu();
		Menu(char* title);

		// DESTRUCTOR.
		~Menu();

		// MEMBER FUNCTION.
		ostream& displayTitle(ostream& out);
		ostream& displayMenu(ostream& out);
		unsigned int run();

		// OPERATOR.
		unsigned int operator~();
		Menu& operator<<(const char* menuitemConent);

		// TYPE CONVERSION.
		operator int();
		operator unsigned();
		operator bool();

	};

	ostream& operator<<(ostream& LO, Menu& RO);
	//ostream& operator<<(ostream& LO, Menu[i]);

}

#endif // !SDDS_MENU_H
