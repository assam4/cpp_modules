#include "Fixed.hpp"

int	main() {
	try {
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
		return 0;
	}
	catch (...) {
		std::cerr << "Unknown Error" << std::endl;
		return 1;
	}
}
