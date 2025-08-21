#include <cstdlib>
#include "Harl.hpp"

int	main() {
	try {
		Harl	harl;
		harl.complain("DEBUG");
		std::cout << std::endl;
		harl.complain("INFO");
		std::cout << std::endl;
		harl.complain("WARNING");
		std::cout << std::endl;
		harl.complain("ERROR");
		std::cout << std::endl;
		return EXIT_SUCCESS;
	}
	catch(...) {
		return EXIT_FAILURE;
	}
}
