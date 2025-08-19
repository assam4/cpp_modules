#include "Zombie.hpp"

static const	std::string Memory_err = "Not enough memory";
static const	std::string Memory_leak = "Exiting with memory leaks";
static const	std::string Name = "Babken";
static const	int N = 4;

int	main() {
	try {
		Zombie	*arr = zombieHorde(N, Name);
		if (!arr)
			throw std::runtime_error(Memory_err);
		for (int i = 0; i < N; ++i) {
			std::cout << i << ": ";
			arr[i].announce();
		}
		delete [] arr;
		arr = NULL;
		return EXIT_SUCCESS;
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	catch (...) {
		std::cerr << Memory_leak << std::endl;
		return EXIT_FAILURE;
	}
}
