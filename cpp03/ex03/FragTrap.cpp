#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("Unnamed", 100, 100, 30) {
	std::cout << "FragTrap derived default ctor called!\n";
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name, 100, 100, 30) {
	std::cout << "FragTrap derived ctor with params called!\n";
}

FragTrap::FragTrap(const FragTrap& oth): ClapTrap(oth) {
	std::cout << "FragTrap derived copy ctor called!\n";
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap dervied dtor called!\n";
}

FragTrap&	FragTrap::operator=(const FragTrap& oth) {
	std::cout << "FragTrap derived operator assignment called!\n";
	if (this != &oth)
		ClapTrap::operator=(oth);
	return *this;
}

void FragTrap::highFivesGuys() {
	if (m_hitPoint)
		std::cout << "FragTrap from ClapTrap " << m_name << " high five!.\n";
}
