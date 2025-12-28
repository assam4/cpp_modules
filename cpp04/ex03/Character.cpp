#include "Character.hpp"

Character::Character(): m_name("Undefined") {
	for (int i = 0; i < 4; ++i) {
		m_inventory[i] = NULL;
		m_unused[i] = NULL;
	}
}

Character::Character(const std::string& name): m_name(name) {
	for (int i = 0; i < 4; ++i) {
		m_inventory[i] = NULL;
		m_unused[i] = NULL;
	}
}

Character::~Character() {
	for (int i = 0; i < 4; ++i)
		delete m_unused[i];
}

Character::Character(const Character& oth) {
	m_name = oth.m_name;
	for (int i = 0; i < 4; ++i) {
		if (oth.m_inventory[i])
			m_inventory[i] = oth.m_inventory[i]->clone();
		else 
			m_inventory[i] = NULL;
		m_unused[i] = m_inventory[i];
	}
}

Character&	Character::operator=(const Character& oth) {
	if (this != &oth) {
		m_name = oth.m_name;
		for (int i = 0; i < 4; ++i) {
			delete m_unused[i];
			if (oth.m_inventory[i])
				m_inventory[i] = oth.m_inventory[i]->clone();
			else
				m_inventory[i] = NULL;
			m_unused[i] = m_inventory[i];
		}
	}
	return *this;
}

const std::string&  Character::getName() const {
	 return m_name;
}
 
void    Character::equip(AMateria* m) {
	if (!m)
		return;
	for (int i = 0; i < 4; ++i)
		if (!m_inventory[i]) {
			delete m_unused[i];
			m_inventory[i] = m->clone();
			m_unused[i] = m_inventory[i];
			break ;
		}
}

void    Character::unequip(int idx) {
	if (idx >= 0 && idx < 4)
		m_inventory[idx] = NULL;
}

void    Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && m_inventory[idx])
		m_inventory[idx]->use(target);
}


