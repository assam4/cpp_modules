#include <cstdlib>
#include "Harl.hpp"

int	main() {
	try {
		Harl	harl;
		harl.complain("DEBUG");
		harl.complain("INFO");
		harl.complain("WARNING");
		harl.complain("ERROR");
		return EXIT_SUCCESS;
	}
	catch(...) {
		return EXIT_FAILURE;
	}
}
