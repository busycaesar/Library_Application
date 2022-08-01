//******************************************************************//
//                                                                  //
// NAME       : DEV JIGISHKUMAR SHAH                                // 
// STUDENT ID : 131623217                                           //
// MAIL ID    : djshah11@myseneca.ca                                //
// COURSE     : OOP 244 NCC                                         //
// SUBMISSION : SENECA LIBRARY APPLICATION (MILESTONE 3)            //
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

#include"Streamable.h"

namespace sdds
{

	std::ostream& operator<<(std::ostream& out, const Streamable& source)
	{

		if (bool(source))
		{

			source.write(out);

		}

		return out;

	}

	std::istream& operator>>(std::istream& in, Streamable& source)
	{

		source.read(in);

		return in;

	}

}