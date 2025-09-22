#include <iostream>
#include <string>
#include "whatever.hpp"

int main( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::string aa = "Abo";
	std::string ba = "Hmbo";
	std::cout << "Before\n";
	std::cout << "a = " << aa << ", b = " << ba << std::endl;
	::swap(aa, ba);
	std::cout << "After\n";
	std::cout << "a = " << aa << ", b = " << ba << std::endl;
	return 0;
};
