/***********************************************************************
// OOP244 Utils Module
// File  utils.h
// Version 1.0
// Author Dev Jigishkumar Shah
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_

#include <iostream>

using namespace std;

namespace sdds
{

	// FUNCTION SIGNATURE.
	int prompt(int min, int max);
	ostream& onlyPrint(const char* f_word, int f_limit, ostream& f_out = cout);

}
#endif // SDDS_UTILS_H_