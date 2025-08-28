#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): m_name("Unnamed"), m_hitPoint(10), m_energyPoint(10), m_damage(0) {
	std::cout << "ClapTrap default ctor called!\n";
}

ClapTrap::ClapTrap(const std::string& name, unsigned hp, unsigned ep, unsigned ad)
	: m_name(name), m_hitPoint(hp), m_energyPoint(ep), m_damage(ad) {
		std::cout << "ClapTrap ctor with params called!\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: m_name(other.m_name), m_hitPoint(other.m_hitPoint), m_energyPoint(other.m_energyPoint), m_damage(other.m_damage) {
	std::cout << "ClapTrap copy ctor called!\n";
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap dtor called!\n";
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& oth) {
	std::cout << "ClapTrap operator assignment called!\n";
	if (this != &oth) {
		m_name = oth.m_name;
		m_hitPoint = oth.m_hitPoint;
		m_energyPoint = oth.m_energyPoint;
		m_damage = oth.m_damage;
	}
	return *this;
}

void	ClapTrap::attack(const std::string& target) {
	if (!m_hitPoint)
		return ;
	else if (!m_energyPoint) 
		std::cout << "ClapTrap " << m_name << " is out of energy points!\n";
	else {
		std::cout << "ClapTrap " << m_name << " attacks "
			<< target << ", causing " << m_damage << " points of damage!\n";
		--m_energyPoint;
	}
}

void	ClapTrap::takeDamage(unsigned amount) {
	if (!m_hitPoint) {
		std::cout << "ClapTrap " << m_name << " the body trembled!\n";
		return ;
	}
	std::cout << "ClapTrap " << m_name << " took " << amount << " points of damage!\n";
	if (m_hitPoint <= amount) {
		std::cout << "ClapTrap " << m_name << " is dead!\n";
		m_hitPoint = 0;
	}
	else 
		m_hitPoint -= amount;
}

void	ClapTrap::beRepaired(unsigned amount) {
	if (!m_hitPoint || !m_energyPoint) 
		return ;
	std::cout << "ClapTrap " << m_name << " has been repaired " << amount << " hit points!\n";
	if (std::numeric_limits<unsigned>::max() - amount < m_hitPoint) {
		std::cout << "ClapTrap " << m_name << " has full hit points!\n";
		m_hitPoint = std::numeric_limits<unsigned>::max();
	}
	else
		m_hitPoint += amount;
	--m_energyPoint;
}
