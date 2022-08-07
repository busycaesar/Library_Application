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

#define _CRT_SECURE_NO_WARNINGS

#include"LibApp.h"
#include<iostream>
#include<fstream>
#include"Book.h"
#include"PublicationSelector.h"

using namespace std;

namespace sdds
{

	// MEMBER FUNCTION.
	void LibApp::setEmpty()
	{

		m_changed = false;
		m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
		m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
		m_PubType << "Book" << "Publication";
		m_NOLPinPPA = 0;

	}

	bool LibApp::confirm(const char* message)
	{

		// VARIABLE DECLARATION.
		Menu temp(message);

		temp << "Yes";
		return (temp.run() == 1);

	}

	void LibApp::load()
	{

		cout << "Loading Data" << endl;

		// VARIABLE DECLARATION.
		ifstream t_file(m_fileName);
		char t_type{};

		for (int i = 0; t_file; i++)
		{

			t_file >> t_type;

			if (t_file)
			{

				switch (t_type)
				{

				case'P':

					m_PPA[i] = new Publication;
					break;

				case'B':
					m_PPA[i] = new Book;
					break;

				}

				if (m_PPA[i])
				{

					t_file >> *m_PPA[i];
					m_NOLPinPPA++;

				}

				if (cin.fail())delete m_PPA[i];

			}
		}

		m_LLRN = m_PPA[m_NOLPinPPA - 1]->getRef();

	}

	void LibApp::save()
	{

		cout << "Saving Data" << endl;

		// VARIABLE DECLARATION.
		ofstream t_file(m_fileName);

		if (t_file)
		{

			for (int i = 0; i < m_NOLPinPPA; i++)
			{

				if (m_PPA[i]->getRef())t_file << *m_PPA[i] << endl;

			}

		}

	}

	int LibApp::search(int f_whichopt)
	{

		// VARIABLE DECLARATION.
		char t_whatTitle[256 + 1], t_type = whichType();
		int t_reference = 0;
		PublicationSelector t_pubAvailable("Select one of the following found matches:", 15);

		cout << "Publication Title: ";
		cin.getline(t_whatTitle, 256);

		for (int i = 0; i < m_NOLPinPPA; i++)
		{

			// THIS WILL NOT LET ANY DELETED PUBLICATION INSIDE AND ONLY ALLOW THE ONCE WHICH HAS SAME TYPE AND TITLE AS USER.
			if ((m_PPA[i]->type() == t_type) && (*m_PPA[i] == t_whatTitle))
			{

				switch (f_whichopt)
				{

				case 1:

					// THIS WILL RETURN ALL THE PUBLICATIONS WHICH ARE NOT DELETED.
					t_pubAvailable << m_PPA[i];
					break;

				case 2:

					// THIS WILL RETURN ALL THE PUBLICATION WHICH ARE NOT DELETE AND ARE ON LOAN TO THE USER.
					if (m_PPA[i]->onLoan())t_pubAvailable << m_PPA[i];
					break;

				case 3:

					// THIS WILL RETURN ALL THE PUBLICATION WHICH ARE NOT DELETE AND ARE AVAILABLE FOR LOAN TO THE USER.
					if (!m_PPA[i]->onLoan())t_pubAvailable << m_PPA[i];
					break;

				}

			}

		}

		if (t_pubAvailable)
		{

			t_pubAvailable.sort();
			t_reference = t_pubAvailable.run();

			if (!t_reference)
			{

				aborted();

			}
			else
			{

				cout << *getPub(t_reference) << endl;

			}

		}
		else
		{

			cout << "No matches found!" << endl;

		}

		return t_reference;

	}

	void LibApp::returnPub()
	{

		cout << "Return publication to the library" << endl;

		// VARIABLE DECLARATION.
		int t_ref = search(2), t_rentDays = 0;
		double t_panelty = 0.0;

		if (t_ref)
		{

			if (confirm("Return Publication?"))
			{

				t_rentDays = Date() - getPub(t_ref)->checkoutDate();

				if (t_rentDays > SDDS_MAX_LOAN_DAYS)
				{

					t_panelty = (t_rentDays - SDDS_MAX_LOAN_DAYS) * SDDS_PANELTY;
					cout << "Please pay $";
					cout.setf(ios::fixed);
					cout.precision(2);
					cout << t_panelty << " penalty for being " << t_rentDays - SDDS_MAX_LOAN_DAYS << " days late!" << endl;
					cout.unsetf(ios::fixed);

				}

				getPub(t_ref)->set(0);
				m_changed = true;
				cout << "Publication returned" << endl;

			}

		}

	}

	void LibApp::newPublication()
	{


		if (m_NOLPinPPA == SDDS_LIBRARY_CAPACITY)
		{

			cout << "Library is at its maximum capacity!" << endl;

		}
		else
		{

			cout << "Adding new publication to the library" << endl;

			// VARIABLE DECLARATION.
			char t_type = whichType();
			Publication* t_publication = nullptr;

			if (!t_type)
			{

				aborted();

			}
			else
			{

				switch (t_type)
				{

				case 'P':
					t_publication = new Publication;
					break;

				case 'B':
					t_publication = new Book;
					break;

				}

				t_publication->read(cin);

				if (cin.fail())
				{

					cin.ignore(1000, '\n');
					aborted();
					delete t_publication;

				}
				else
				{

					if (confirm("Add this publication to the library?"))
					{

						if (bool(t_publication))
						{

							m_LLRN++;
							t_publication->setRef(m_LLRN);
							m_PPA[m_NOLPinPPA] = t_publication;
							m_NOLPinPPA++;
							m_changed = true;

							cout << "Publication added" << endl;

						}
						else
						{

							cout << "Failed to add publication!";
							delete t_publication;

						}

					}
					else
					{

						aborted();
						delete t_publication;

					}

				}

			}

		}

	}

	void LibApp::removePublication()
	{

		cout << "Removing publication from the library" << endl;

		// VARIABLE DECLARATION.
		int t_ref = search(1);

		if (t_ref)
		{

			if (confirm("Remove this publication from the library?"))
			{

				(getPub(t_ref))->setRef(0);
				m_changed = true;
				cout << "Publication removed" << endl;

			}

		}

	}

	void LibApp::checkOutPub()
	{

		cout << "Checkout publication from the library" << endl;

		// VARIABLE DECLARATION.
		int t_ref = search(3), t_memNum = 0, t_temp = 0;

		if (t_ref)
		{

			if (confirm("Check out publication?"))
			{

				cout << "Enter Membership number: ";

				do
				{

					if (t_temp)
					{

						cout << "Invalid membership number, try again: ";

					}

					cin >> t_memNum;
					t_temp = 1;

				} while (t_memNum < 9999 || t_memNum > 100000);

				(getPub(t_ref))->set(t_memNum);
				m_changed = true;
				cout << "Publication checked out" << endl;

			}

		}

	}

	char LibApp::whichType()const
	{

		// VARIABLE DECLARATION.
		char t_type = 'P';
		int t_pubType = m_PubType.run();

		cin.ignore(1000, '\n');

		switch (t_pubType)
		{
		case 1:
			t_type = 'B';
			break;
		case 2:
			t_type = 'P';
			break;
		default:
			t_type = 0;
			break;
		}

		return t_type;

	}

	void LibApp::aborted()const
	{

		cout << "Aborted!" << endl;

	}

	Publication* LibApp::getPub(int libRef)const
	{

		for (int i = 0; i < m_NOLPinPPA; i++)
		{

			if (m_PPA[i]->getRef() == libRef)return m_PPA[i];

		}

		return nullptr;

	}

	// CONSTRUCTOR.
	LibApp::LibApp(const char* f_fileName)
	{

		setEmpty();
		strcpy(m_fileName, f_fileName);

		if (m_fileName != nullptr) load();

	}

	LibApp::~LibApp()
	{

		for (int i = 0; i < m_NOLPinPPA; i++)delete m_PPA[i];

	}

	// MEMBER FUNCTION.
	void LibApp::run()
	{

		// VARIABLE DECLARATION.
		int t_selMain = 1, t_selExit = 0;

		while (t_selMain)
		{

			t_selMain = m_mainMenu.run();

			switch (t_selMain)
			{

			case 1:

				newPublication();
				cout << endl;
				break;

			case 2:

				removePublication();
				cout << endl;
				break;

			case 3:

				checkOutPub();
				cout << endl;
				break;

			case 4:

				returnPub();
				cout << endl;
				break;

			case 0:

				if (m_changed)
				{

					t_selExit = m_exitMenu.run();

					switch (t_selExit)
					{

					case 1:

						save();
						break;

					case 0:

						if (confirm("This will discard all the changes are you sure?"));
						break;

					case 2:

						t_selMain = 1;
						break;

					}

				}

				break;

			}

		}

		cout << endl << "-------------------------------------------" << endl
			<< "Thanks for using Seneca Library Application" << endl;

	}

}