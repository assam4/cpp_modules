#include "Zombie.hpp"

static const	std::string Memory_err = "Not enough memory";
static const	std::string Memory_leak = "Exiting with memory leaks";
static const	std::string Name_1 = "Babken";
static const	std::string Name_2 = "Varazdat";

int	main() {
	try {
		Zombie	*test1 = newZombie(Name_1);
		if (!test1)
			throw std::runtime_error(Memory_err);
		test1->announce();
		delete test1;
		test1 = NULL;
		randomChump(Name_2);
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
