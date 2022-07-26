#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H

#include<iostream>

namespace sdds
{

	// CLASS
	class Streamable
	{

		// DESTRUCTOR.
		~Streamable() {}

		// METHOD.
		virtual std::ostream& write(std::ostream& out)const = 0;
		virtual std::istream& read(std::istream& in) = 0;
		virtual bool conIO(std::ios& iosObj)const = 0;
		virtual operator bool()const = 0;


	};

	// HELPER OPERATOR.
	std::ostream& operator<<(std::ostream&, Streamable& source);
	std::istream& operator>>(std::istream&, Streamable& source);

}

#endif // !SDDS_STREAMABLE_H
