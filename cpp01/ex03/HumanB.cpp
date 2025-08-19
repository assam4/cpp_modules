#include "HumanB.hpp"

HumanB::~HumanB() {
}

HumanB::HumanB(const std::string& name) {
	this->m_name = name;
	this->m_weapon = NULL;
}

void	HumanB::setWeapon(const Weapon& w) {
	this->m_weapon = &w;
}

void	HumanB::attack() const {
	std::cout << this->m_name << Attack << this->m_weapon->getType() << std::endl;
}
