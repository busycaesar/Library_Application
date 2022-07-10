/***********************************************************************
// OOP244 Utils Module:
// File  utils.cpp
// Version
// Date
// Author
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "Utils.h"

using namespace std;

namespace sdds
{

	// FUNCTION DEFINATION.
	int prompt(int min, int max)
	{

		// VARIABLE DECLARATION.
		int selection = 0, temp = 0;

		do
		{

			if (temp)
			{

				cout << "Invalid Selection, try again: ";

			}

			cin >> selection;

		} while (selection >= min && selection <= max);

		return selection;

	}

}