#include"LibApp.h"

namespace sdds
{

	// MEMBER FUNCTION.
	void LibApp::setEmpty()
	{

		m_changed = false;
		m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
		m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";

	}
	bool LibApp::confirm(const char* message)
	{

		// VARIABLE DECLARATION.
		Menu temp(message);

		temp << "yes";
		return (temp.run() == 1);

	}

	void LibApp::load()
	{

		cout << "Loading Data" << endl;

	}

	void LibApp::save()
	{

		cout << "Saving Data" << endl;

	}

	void LibApp::search()
	{

		cout << "Searching for publication" << endl;

	}

	void LibApp::returnPub()
	{

		search();
		cout << "Returning publication" << endl;
		cout << "Publication returned" << endl;
		m_changed = true;

	}

	void LibApp::newPublication()
	{

		cout << "Adding new publication to library" << endl;

		if (confirm("Add this publication to library?"))
		{

			m_changed = true;
			cout << "Publication added" << endl;

		}

	}

	void LibApp::removePublication()
	{

		cout << "Removing publication from library" << endl;
		search();
		if (confirm("Remove this publication from the library?"))
		{

			m_changed = true;
			cout << "Publication removed" << endl;

		}

	}

	void LibApp::checkOutPub()
	{

		search();

		if (confirm("Check out publication?"))
		{

			m_changed = true;
			cout << "Publication checked out" << endl;

		}

	}

	// CONSTRUCTOR.
	LibApp::LibApp()
	{

		setEmpty();
		load();

	}

	// MEMBER FUNCTION.
	void LibApp::run()
	{

		// VARIABLE DECLARATION.
		unsigned int temp = 1;

		while (temp != 0)
		{

			temp = m_mainMenu.run();

			switch (temp)
			{

			case 1:
				newPublication();
				break;
			case 2:
				removePublication();
				break;
			case 3:
				checkOutPub();
				break;
			case 4:
				returnPub();
				break;
			}

		}

		if (m_changed)
		{

			switch (m_exitMenu.run())
			{

			case 1:
				save();
				break;
			case 2:
				run();
				break;
			case 0:
				if (!confirm("This will discard all the changes are you sure?"))
				{

					run();

				}
				break;

			}

		}

		cout << "-------------------------------------------" << endl <<
			"Thanks for using Seneca Library Application";

	}

}