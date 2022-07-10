/*


#include<iostream>
#include<cstring>
#include"Menu.h"
#include"Utils.h"

using namespace std;

namespace sdds
{

	MenuItem::MenuItem()
	{

		setEmpty();

	}

	MenuItem::MenuItem(const char* item)
	{

		setEmpty();

		m_item = new char(strlen(item) + 1);
		strcpy(m_item, item);

	}

	MenuItem::MenuItem(const MenuItem& source)
	{

		m_item = new char[strlen(source.m_item) + 1];
		strcpy(m_item, source.m_item);

	}

	MenuItem::~MenuItem()
	{

		delete[] m_item;

	}

	void MenuItem::setEmpty()
	{

		m_item = nullptr;

	}

	bool MenuItem::isEmpty()
	{

		return (m_item == nullptr);

	}

	ostream& MenuItem::display(ostream& out)
	{

		if (isEmpty())
		{

			out << m_item;

		}

		return out;

	}

	MenuItem::operator bool()
	{

		return !isEmpty();

	}

	MenuItem::operator const char* ()
	{

		return m_item;

	}

	MenuItem& MenuItem::operator=(const MenuItem& source)
	{

		if (this != &source)
		{

			delete[] m_item;
			setEmpty();

			m_item = new char[strlen(source.m_item) + 1];
			strcpy(m_item, source.m_item);

		}

		return *this;

	}

	Menu::Menu()
	{

		setEmpty();

	}

	Menu::Menu(char* title)
	{

		setEmpty();

		m_MenuItem = new char[strlen(title) + 1];
		strcpy(m_MenuItem, title);

	}

	Menu::~Menu()
	{

		for (int i = 0; i < m_totalItems; i++)
		{

			delete[] m_items[i];

		}

	}

	void Menu::setEmpty()
	{

		m_MenuItem = nullptr;
		m_items[0] = nullptr;
		m_totalItems = 0;

	}

	ostream& Menu::displayTitle(ostream& out)
	{

		if (m_MenuItem != nullptr)
		{

			out << m_MenuItem;

		}

		return out;

	}

	ostream& Menu::displayMenu(ostream& out)
	{

		displayTitle(out);
		out << ":" << endl;

		for (int i = 0; i < m_totalItems; i++)
		{

			out.width(2);
			out << right << i + 1;
			out << "- ";
			m_items[i]->display(out) << endl;

		}

		out << "0- Exit" << endl << "> ";

		return out;

	}

	unsigned int Menu::run()
	{

		// VARIABLE DECLARATION.
		int selection = 0, temp = 0;

		displayMenu(cout);
		selection = prompt(0, m_totalItems);

		return selection;

	}

	unsigned int Menu::operator~()
	{

		return run();

	}

	Menu& Menu::operator<<(const char* newItem)
	{

		if (m_totalItems < MAX_MENU_ITEMS)
		{

			// VARIABLE DECLARATION.
			MenuItem temp(newItem);

			m_items[m_totalItems++] = &temp;

		}

		return *this;

	}

	Menu::operator int()
	{

		return m_totalItems;

	}

	Menu::operator unsigned()
	{

		return int(this);

	}

	Menu::operator bool()
	{

		return m_totalItems > 0;

	}

	ostream& operator<<(ostream& LO, Menu& RO)
	{

		RO.displayTitle(LO);

		return LO;

	}



}


*/