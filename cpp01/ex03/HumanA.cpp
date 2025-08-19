#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, const Weapon& weapon) {
	this->m_weapon = &weapon;
	this->m_name = name;
}

HumanA::~HumanA() {
}

void	HumanA::attack() const {
	std::cout << this->m_name << Attack << this->m_weapon->getType() << std::endl;
}
