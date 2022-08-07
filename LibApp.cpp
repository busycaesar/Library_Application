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

#include"LibApp.h"
#include<iostream>
#include<fstream>
#include"Book.h"
#include"PublicationSelector.h"

namespace sdds
{

	// MEMBER FUNCTION.
	void LibApp::setEmpty()
	{

		m_changed = false;
		m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
		m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
		m_PubType << "Book" << "Publication";

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

		// VARIABLE DECLARATION.
		ifstream t_file(m_fileName);
		char t_type{};

		m_NOLPinPPA = 0;

		cout << "Loading Data" << endl;

		while (t_file)
		{

			t_file >> t_type;
			t_file.ignore();

			if (t_file)
			{

				switch (t_type)
				{

				case'P':
					m_PPA[m_NOLPinPPA] = new Publication;
					break;

				case'B':
					m_PPA[m_NOLPinPPA] = new Book;
					break;

				}

				if (m_PPA[m_NOLPinPPA])
				{

					t_file >> *m_PPA[m_NOLPinPPA];
					m_NOLPinPPA++;

				}

			}

		}

		m_LLRN = m_PPA[m_NOLPinPPA - 1]->getRef();

	}

	void LibApp::save()
	{

		cout << "Saving Data" << endl;

		// VARIABLE DECLARATION.
		ofstream t_file(m_fileName);

		for (int i = 0; i < m_NOLPinPPA; i++)
		{

			if (m_PPA[i]->getRef())t_file << *m_PPA[i] << endl;

		}

	}

	int LibApp::search(int f_whichopt)
	{

		// VARIABLE DECLARATION.
		PublicationSelector t_pubAvailable("Select one of the following found matches:");
		char t_whatTitle[256 + 1];
		int t_reference = 0;
		char t_type = whichType();

		cout << "Publication Title: ";
		cin.getline(t_whatTitle, 256, '\n');

		for (int i = 0; i < m_NOLPinPPA; i++)
		{

			// THIS WILL NOT LET ANY DELETED PUBLICATION INSIDE AND ONLY ALLOW THE ONCE WHICH HAS SAME TYPE AND TITLE AS USER.
			if (m_PPA[i]->getRef() && (m_PPA[i]->type() == t_type) && (*m_PPA[i] == t_whatTitle))
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

				cout << *getPub(t_reference) << endl;/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// CHECK IF THEY ASKED TO IMPLEMENT THIS CODE OR NOT.

			}

		}
		else
		{

			cout << "No matches found!";

		}

		return t_reference;

	}

	void LibApp::returnPub()
	{

		//search();
		cout << "Returning publication" << endl;
		cout << "Publication returned" << endl;
		m_changed = true;

	}

	void LibApp::newPublication()
	{


		if (m_NOLPinPPA == SDDS_LIBRARY_CAPACITY)
		{

			cout << "Library is at its maximum capacity!";

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

			if (!cin)
			{

				cin.ignore(1000, '\n');
				aborted();
				delete[] t_publication;

			}
			else
			{

				if (confirm("Add this publication to the library?") && bool(t_publication))
				{

					m_LLRN++;
					t_publication->setRef(m_LLRN);
					m_PPA[m_NOLPinPPA] = t_publication;
					m_NOLPinPPA++;
					m_changed = true;

					cout << "Publication added" << endl;

				}
				else if (!bool(t_publication))
				{

					cout << "Failed to add publication!";
					delete[] t_publication;

				}
				else
				{

					aborted();
					delete[] t_publication;

				}

			}


		}

	}

	void LibApp::removePublication()
	{

		cout << "Removing publication from library" << endl;

		int t_ref = search(1);

		if (t_ref && confirm("Remove this publication from the library?"))
		{

			(getPub(t_ref))->setRef(0);
			m_changed = true;
			cout << "Publication removed" << endl;

		}

	}

	void LibApp::checkOutPub()
	{

		cout << "Checkout publication from the library" << endl;

		// VARIABLE DECLARATION.
		int t_ref = search(3), t_memNum, t_temp = 0;

		if (t_ref && confirm("Check out publication?"))
		{

			do
			{

				if (t_temp)
				{

					cout << "Checkout publication from the library";

				}

				cin >> t_memNum;
				t_temp = 1;

			} while (t_memNum > 9999 && t_memNum < 100000);

			(getPub(t_ref))->set(t_memNum);
			m_changed = true;
			cout << "Publication checked out" << endl;

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

	}

	// CONSTRUCTOR.
	LibApp::LibApp(const char* f_fileName)
	{

		setEmpty();
		strcpy(m_fileName, f_fileName);
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

			case 0:

				if (m_changed)
				{

					switch (m_exitMenu.run())
					{

					case 1:
						save();
						break;

					case 2:

						// IF THE USER ENTERS 2, WE WANT THIS WHOLE FUNCTION TO REPEAT. HENCE, I AM CONVERTING THE TEMP VALUE TO NOT EQUAL TO 0, SO THAT THE PROGRAM ENTERS THE WHILE LOOP AGAIN. ALSO, THIS WILL PRINT A NEW LINE AS WE HAVE A FUNCTION BELOW TO PRINT A NEW LINE IF TEMP IS NOT 0.
						temp = 1;
						break;

					case 0:

						if (!confirm("This will discard all the changes are you sure?"))
						{

							run();

						}

						break;

					}

				}

				break;

			}

			// IF TEMP, THAT IS, THE SELECTED OPTION FROM THE MAIN MENU IS NOT 0, THAT IS TO EXIT THE APPLICATION, IT WILL PRINT THE CONTENT INTO NEW LINE.
			if (temp)
			{

				cout << endl;

			}

		}

		cout << endl << "-------------------------------------------" << endl <<
			"Thanks for using Seneca Library Application" << endl;

	}

}