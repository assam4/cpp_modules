#include <iostream>
#include <cctype>
#include <cstdlib>

static const char *message_na = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
static const char space = ' ';

static char *string_transform(char *str) {
	if (!str)
		return NULL;
	for (int i = 0; str[i]; ++i)
		str[i] = std::toupper(static_cast<unsigned char>(str[i]));
	return str;
}

static void	argv_parse(int argc, char **argv) {
	if (argc == 1) 
			std::cout << message_na;
		else
			for (int x = 1; x < argc; ++x) {
				if (x != 1)
					std::cout << space;
				std::cout << string_transform(argv[x]);
			}
}

int	main(int argc, char **argv) {
	try {
		argv_parse(argc, argv);
		std::cout << std::endl;
	}
	catch (...) {
		std::cerr << "Unknown error!" << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}	
