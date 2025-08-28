#include "ClapTrap.hpp"

int	main() {
	try {
		ClapTrap clap1("CL4P");
		ClapTrap clap2("TR4P");
		clap1.attack("TR4P");
		clap2.takeDamage(3);
		for (int i = 0; i < 11; i++)
			clap1.attack("TR4P");
		clap2.takeDamage(50);
		clap2.attack("CL4P");
		clap1.beRepaired(5);
		ClapTrap clap3("R3P");
		clap3.takeDamage(4);
		clap3.beRepaired(3);
		ClapTrap clap4 = clap3;
		clap4.attack("dummy");
		ClapTrap clap5("ASSIGN");
		clap5 = clap1;
		clap5.attack("dummy2");
		return 0;
	}
	catch (...) {
		std::cout << "Error!" << std::endl;
		return 1;
	}
}
