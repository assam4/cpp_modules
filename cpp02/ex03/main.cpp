#include "Point.hpp"

int	main() {
	try {
		Point	a(0, 0);
		Point	b(10, 0);
		Point	c(0, 10);

		Point p1(3, 3);
		std::cout << "p1 inside? " << (bsp(a, b, c, p1) ? "YES" : "NO") << std::endl;
		Point p2(10, 10);
		std::cout << "p2 inside? " << (bsp(a, b, c, p2) ? "YES" : "NO") << std::endl;
		Point p3(5, 0);
		std::cout << "p3 inside? " << (bsp(a, b, c, p3) ? "YES" : "NO") << std::endl;
		Point p4(0, 0);
		std::cout << "p4 inside? " << (bsp(a, b, c, p4) ? "YES" : "NO") << std::endl;
		Point p5(2, 5);
		std::cout << "p5 inside? " << (bsp(a, b, c, p5) ? "YES" : "NO") << std::endl;
		return 0;
	}
	catch(...) {
		std::cerr << "Unknown error\n" << std::endl;
		return 1;
	}
}
