#include "ClapTrap.hpp"

int	main(void)
{
	try {
		ClapTrap clap("CL4P");
		clap.attack("target");
		clap.takeDamage(20);
		clap.beRepaired(50);
		ClapTrap clap2("CL4P2");
		clap.attack("CL4P2");
		clap2.takeDamage(20);
		ClapTrap clap3 = clap2;
		clap2.attack("CL4P3");
		clap3.takeDamage(8);
		ClapTrap clap4("CL4P4");
		clap4 = clap;
		clap.attack("CL4P4");
		clap4.takeDamage(5);
		return 0;
	}
	catch (...) {
		std::cout << "Error!" << std::endl;
		return 1;
	}
}
