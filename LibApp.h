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
		Menu m_mainMenu{ "Seneca Libray Application" };
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
