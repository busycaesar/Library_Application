#ifndef SDDS_MENU_H
#define SDDS_MENU_H

#include<iostream>
#include<cstring>

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
		MenuItem* m_items[MAX_MENU_ITEMS];
		int m_totalItems;

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
		const char* operator[](int i)const;

		// TYPE CONVERSION.
		operator int()const;
		operator unsigned int()const;
		operator bool()const;

	};

	ostream& operator<<(ostream& LO, Menu& RO);

}

#endif // !SDDS_MENU_H 
