#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {
	try {
		if (argc != 2)
			throw std::runtime_error("Invalid argumnents count");
		RPN calculator;
		std::cout << calculator(std::string(argv[1])) << std::endl;
		return 0;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	catch (...) {
		return 1;
	}
}
