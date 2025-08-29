#include "DiamondTrap.hpp"
/*
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
		std::cout << "\n=== FragTrap test ===\n";
		FragTrap frag("FR4G");
		frag.attack("TargetF");
		frag.takeDamage(30);
		frag.beRepaired(20);
		frag.highFivesGuys();
		std::cout << "\n=== DiamondTrap test ===\n";
		DiamondTrap diamond("DIA1");
		diamond.attack("TargetD");   // вызывает ScavTrap::attack
		diamond.takeDamage(40);      // от ClapTrap
		diamond.beRepaired(25);      // от ClapTrap
		diamond.highFivesGuys();     // от FragTrap
		diamond.guardGate();         // от ScavTrap
		diamond.whoAmI();            // особая функция DiamondTrap
		std::cout << "\n=== DiamondTrap copy/assignment test ===\n";
		DiamondTrap dia2 = diamond;
		dia2.whoAmI();
		dia2.attack("TargetD2");
		DiamondTrap dia3("DIA3");
		dia3 = diamond;
		dia3.whoAmI();
		dia3.attack("TargetD3");
		std::cout << "\n=== DiamondTrap death test ===\n";
		diamond.takeDamage(200);
		diamond.attack("TargetD4");
		diamond.beRepaired(50);
		diamond.whoAmI();
		return 0;
	}
	catch (...) {
		std::cout << "Error!" << std::endl;
		return 1;
	}
}
*/

#include "DiamondTrap.hpp"

int main() {
    std::cout << "=== Testing DiamondTrap with base class pointer ===\n";

    // Указатель на базовый класс
    ClapTrap* ptr = new DiamondTrap("DIA_PTR");

    // Проверка методов через базовый указатель
    ptr->attack("TargetBase");       // должно вызвать ScavTrap::attack
    ptr->takeDamage(20);             // ClapTrap
    ptr->beRepaired(10);             // ClapTrap

    // Приведение к DiamondTrap для вызова особого метода
    DiamondTrap* dptr = dynamic_cast<DiamondTrap*>(ptr);
    if (dptr) {
        dptr->whoAmI();              // DiamondTrap specific
    }

    // Освобождение памяти
    delete ptr;

    return 0;
}

