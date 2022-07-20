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

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
#include"Menu.h"
#include"Utils.h"

using namespace std;

namespace sdds
{

	// 1. IMPLEMENTATION OF CLASS MenuItem.

	MenuItem::MenuItem()
	{

		setEmpty();

	}

	MenuItem::MenuItem(const char* item)
	{

		setEmpty();
		setItem(item);

	}

	MenuItem::~MenuItem()
	{

		delete[] m_item;
		m_item = nullptr;

	}

	void MenuItem::setEmpty()
	{

		m_item = nullptr;

	}

	bool MenuItem::isEmpty()const
	{

		return (m_item == nullptr);

	}

	void MenuItem::setItem(const char* item)
	{

		m_item = new char[strlen(item) + 1];
		strcpy(m_item, item);

	}

	ostream& MenuItem::display(ostream& out)const
	{

		if (!isEmpty())
		{

			out << m_item;

		}

		return out;

	}

	MenuItem::operator bool()const
	{

		return !isEmpty();

	}

	MenuItem::operator const char* ()const
	{

		return m_item;

	}

	// 2. IMPLEMENTATION OF CLASS Menu.

	void Menu::setEmpty()
	{

		m_MenuTitle = nullptr;
		m_items[0] = nullptr;
		m_totalItems = 0;

	}

	Menu::Menu()
	{

		setEmpty();

	}

	Menu::Menu(const char* title)
	{

		setEmpty();

		m_MenuTitle = new char[strlen(title) + 1];
		strcpy(m_MenuTitle, title);

	}

	Menu::~Menu()
	{

		delete[] m_MenuTitle;
		m_MenuTitle = nullptr;

		for (unsigned int i = 0; i < m_totalItems; i++)
		{

			delete m_items[i];
			m_items[i] = nullptr;

		}

	}


	ostream& Menu::displayTitle(ostream& out)const
	{

		if (m_MenuTitle != nullptr)
		{

			out << m_MenuTitle;

		}

		return out;

	}

	ostream& Menu::displayMenu(ostream& out)const
	{

		displayTitle(out) << endl;

		for (unsigned int i = 0; i < m_totalItems; i++)
		{

			out.width(2);
			out << right << i + 1;
			out << "- ";
			m_items[i]->display(out) << endl;

		}

		out << " 0- Exit" << endl << "> ";

		return out;

	}

	unsigned int Menu::run()const
	{

		// VARIABLE DECLARATION.
		int selection = 0;

		displayMenu(cout);
		selection = prompt(0, m_totalItems);

		return selection;

	}

	unsigned int Menu::operator~()const
	{

		return run();

	}

	Menu& Menu::operator<<(const char* newItem)
	{

		if (m_totalItems < MAX_MENUITEMS)
		{

			m_items[m_totalItems] = new MenuItem(newItem);
			m_totalItems++;

		}

		return *this;

	}

	const char* Menu::operator[](unsigned int i)const
	{

		if (i <= m_totalItems && i >= 0)
		{

			return m_items[i]->m_item;

		}
		else
		{

			return "error";

		}

	}

	Menu::operator int()const
	{

		return m_totalItems;

	}

	Menu::operator unsigned int()const
	{

		return m_totalItems;

	}

	Menu::operator bool()const
	{

		return (m_totalItems > 0);

	}

	ostream& operator<<(ostream& LO, Menu& RO)
	{

		RO.displayTitle(LO);

		return LO;

	}

}