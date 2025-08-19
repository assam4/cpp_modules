#include "Weapon.hpp"

const std::string Attack = " attacks with their ";

Weapon::Weapon() {
}

Weapon::Weapon(const std::string& type) {
	this->type = type;
}

Weapon::Weapon(const Weapon& other) {
	this->type = other.type;
}

Weapon& Weapon::operator=(const Weapon& other) {
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

Weapon::~Weapon() {
}

const std::string&	Weapon::getType() const {
	return this->type;
}

void	Weapon::setType(const std::string& newType) {
	this->type = newType;
}
