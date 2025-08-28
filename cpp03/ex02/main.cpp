#include "FragTrap.hpp"
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
		std::cout << "\n=== ScavTrap copy/assignment test ===\n";
		ScavTrap scav2 = scav;
		scav2.attack("Target3");
		ScavTrap scav3("SC4V3");
		scav3 = scav;
		scav3.attack("Target4");
		std::cout << "\n=== ScavTrap energy depletion test ===\n";
		for (int i = 0; i < 55; ++i)
			scav.attack("Dummy");
		std::cout << "\n=== ScavTrap death test ===\n";
		scav.takeDamage(200);
		scav.attack("Target5");
		scav.beRepaired(50);
		scav.guardGate();
		std::cout << "\n=== FragTrap test ===\n";
		FragTrap frag("FR4G");
		frag.attack("TargetF");
		frag.takeDamage(30);
		frag.beRepaired(20);
		frag.highFivesGuys();
		std::cout << "\n=== FragTrap copy/assignment test ===\n";
		FragTrap frag2 = frag;
		frag2.attack("TargetF2");
		FragTrap frag3("FR4G3");
		frag3 = frag;
		frag3.attack("TargetF3");
		std::cout << "\n=== FragTrap death test ===\n";
		frag.takeDamage(200);
		frag.attack("TargetF4");
		frag.beRepaired(50);
		frag.highFivesGuys();
		return 0;
	}
	catch (...) {
		std::cout << "Error!" << std::endl;
		return 1;
	}
}
