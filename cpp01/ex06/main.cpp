#include <cstdlib>
#include "Harl.hpp"

int	main(int argc, char **argv) {
	try {
		if (argc == 2) {
			Harl	harl;
			harl.complain(argv[1]);
		}
		return EXIT_SUCCESS;
	}
	catch(...) {
		return EXIT_FAILURE;
	}
}
