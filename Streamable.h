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

#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H

#include<iostream>

namespace sdds
{

	// ABSTRACT CLASS
	class Streamable
	{

	public:

		// DESTRUCTOR.
		~Streamable() {}

		// METHOD.
		virtual std::ostream& write(std::ostream& out)const = 0;
		virtual std::istream& read(std::istream& in) = 0;
		virtual bool conIO(std::ios& iosObj)const = 0;

		// TYPE CONVERSION.
		virtual operator bool()const = 0;

	};

	// HELPER OPERATOR.
	std::ostream& operator<<(std::ostream& out, const Streamable& source);
	std::istream& operator>>(std::istream& in, Streamable& source);

}

#endif // !SDDS_STREAMABLE_H
