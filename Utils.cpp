/***********************************************************************
// OOP244 Utils Module:
// File  utils.cpp
// Version 1.0
// Date 15 / 07 / 2022
// Author Dev Jigishkumar Shah
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

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
				cin.clear();
				cin.ignore(1000, '\n');

			}

			cin >> selection;
			temp = 1;

		} while (selection < min || selection > max || cin.fail());

		return selection;

	}

}