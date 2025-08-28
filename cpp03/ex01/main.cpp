#include "ScavTrap.hpp"

int main() {
	try {
		std::cout << "=== ClapTrap test ===\n";
		ClapTrap clap("CL4P");
		clap.attack("Target1");
		clap.takeDamage(5);
		clap.beRepaired(3);
		std::cout << "\n=== ScavTrap test ===\n";
		ScavTrap scav("SC4V");
		scav.attack("Target2");
		scav.takeDamage(20);
		scav.beRepaired(10);
		scav.guardGate();
		std::cout << "\n=== Copy and assignment test ===\n";
		ScavTrap scav2 = scav;
		scav2.attack("Target3");
		ScavTrap scav3("SC4V3");
		scav3 = scav;
		scav3.attack("Target4");
		std::cout << "\n=== Energy depletion test ===\n";
		for (int i = 0; i < 55; ++i)
			scav.attack("Dummy");
		std::cout << "\n=== Death test ===\n";
		scav.takeDamage(200);
		scav.attack("Target5");
		scav.beRepaired(50);
		scav.guardGate();
		return 0;
	}
	catch (...) {
		std::cout << "Error!" << std::endl;
		return 1;
	}
}
