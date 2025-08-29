#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(std::string("Unnamed") + std::string("_clap_name"), 100, 50, 30)
							, m_name("Unnamed") {
	std::cout << "DiamondTrap dervied default ctor called!\n";
}

DiamondTrap::DiamondTrap(const std::string& name): ClapTrap(name + std::string("_clap_name"), 100, 50, 30)
													, m_name(name) {
	std::cout << "DiamondTrap dervied ctor with params called!\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& oth) : ClapTrap(oth), ScavTrap(oth)
												  , FragTrap(oth), m_name(oth.m_name) {
	std::cout << "DiamondTrap dervied copy ctor called!\n";
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap dervied dtor called!\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& oth) {
	std::cout << "DiamondTrap derived operator assignment called!\n";
	if (this != &oth) {
		m_name = oth.m_name;
		ClapTrap::operator=(oth);
	}
	return *this;
}

void	DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI() {
	std::cout << "I am DiamondTrap name: " << m_name
		<< "\n My ClapTrap name is: " << ClapTrap::m_name << std::endl;
}
