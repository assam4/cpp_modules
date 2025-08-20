#include <cstdlib>
#include <iostream>
#include "StreamEditor.hpp"

int	main(int argc, char** argv) {
	try {
		if (argc != 4)
			return EXIT_SUCCESS;
		StreamEditor delivery;
		if (!delivery.set_istream(argv[1]) || !delivery.set_ostream("replaced.txt"))
			return EXIT_FAILURE;
		delivery.set_filter(argv[2], argv[3]);
		while (delivery.readline())
			delivery.writeline();
		return EXIT_SUCCESS;
	}
	catch (...) {
		std::cerr << "Undefined error!" << std::endl;
		return EXIT_FAILURE;
	}
}
