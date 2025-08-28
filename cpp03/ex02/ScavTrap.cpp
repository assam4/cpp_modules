#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("Unnamed", 100, 50 , 20) {
	std::cout << "ScavTrap derived default ctor called!\n";
}

ScavTrap::ScavTrap(const std::string& name)
	: ClapTrap(name, 100, 50, 20) {
		std::cout << "ScavTrap derived ctor with params called!\n";
}

ScavTrap::ScavTrap(const ScavTrap& oth): ClapTrap(oth) {
	std::cout << "ScavTrap dervied copy ctor called!\n";
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap derived dtor called!\n";
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& oth) {
	std::cout << "ScavTrap derived operator assignment called!\n";
	if (this != &oth)
		ClapTrap::operator=(oth);
	return *this;
}

void	ScavTrap::attack(const std::string& target) {
	if (!m_hitPoint || !m_energyPoint)
		return ;
	std::cout << "ScavTrap " << m_name << " attacked " << target 
		<< " causing " << m_damage << " points of damage!\n";
	--m_energyPoint;
}

void	ScavTrap::guardGate() {
	if (!m_hitPoint)
		return ;
	std::cout << "ScavTrap " << m_name << "  is now in Gate keeper mode\n";
}
