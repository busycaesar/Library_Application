//#ifndef SDDS_MENU_H
//#define SDDS_MENU_H
//
//#include<iostream>
//
//using namespace std;
//
//namespace sdds
//{
//
//	// CONSTANTS.
//	const int MAX_MENU_ITEMS = 20;
//
//	// CLASS.
//	class MenuItem
//	{
//
//		// DATA MEMBER.
//		char* m_item;
//
//		// MEMBER FUNCTIONS.
//		void setEmpty();
//		bool isEmpty();
//
//		// CONSTRUCTOR.
//		MenuItem();
//		MenuItem(const char* item);
//		MenuItem(const MenuItem& source);
//
//		// DESTRUCTOR.
//		~MenuItem();
//
//	public:
//
//		// MEMBER FUNCTIONS.
//		ostream& display(ostream& out);
//
//		// TYPE CONVERSION.
//		operator bool();
//		operator const char* ();
//
//		// OPERATOR.
//		MenuItem& operator=(const MenuItem& source);
//
//		// FRIEND.
//		friend class Menu;
//
//	};
//
//	class Menu
//	{
//
//		// DATA MEMBERS.
//		char* m_MenuItem;
//		MenuItem* m_items[MAX_MENU_ITEMS];
//		int m_totalItems;
//
//		// MEMBER FUNCTION.
//		void setEmpty();
//
//	public:
//
//		// CONSTRUCTOR.
//		Menu();
//		Menu(const char* title);
//
//		// DESTRUCTOR.
//		~Menu();
//
//		// MEMBER FUNCTION.
//		ostream& displayTitle(ostream& out);
//		ostream& displayMenu(ostream& out);
//		unsigned int run();
//
//		// OPERATOR.
//		unsigned int operator~();
//		Menu& operator<<(const char* menuitemConent);
//		ostream& operator[](int i);
//
//		// TYPE CONVERSION.
//		operator int();
//		operator unsigned();
//		operator bool();
//
//	};
//
//	ostream& operator<<(ostream& LO, Menu& RO);
//
//}
//
//#endif // !SDDS_MENU_H
