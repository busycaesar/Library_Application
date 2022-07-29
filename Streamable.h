#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H

#include<iostream>

namespace sdds
{

	// ABSTRACT CLASS
	class Streamable
	{

		// DESTRUCTOR.

		// METHOD.
		virtual bool conIO(std::ios& iosObj)const = 0;

	public:

		~Streamable() {}
		
		// METHOD.
		virtual std::ostream& write(std::ostream& out)const = 0;
		virtual std::istream& read(std::istream& in) = 0;

		// TYPE CONVERSION.
		virtual operator bool()const = 0;

	};

	// HELPER OPERATOR.
	std::ostream& operator<<(std::ostream& out, const Streamable& source);
	std::istream& operator>>(std::istream& in, Streamable& source);

}

#endif // !SDDS_STREAMABLE_H
