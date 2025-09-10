#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; ++i)
		m_inventory[i] = NULL;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; ++i)
		delete m_inventory[i];
}

MateriaSource::MateriaSource(const MateriaSource& oth) {
	for (int i = 0; i < 4; ++i)
		if (oth.m_inventory[i])
			m_inventory[i] = oth.m_inventory[i]->clone();
		else
			m_inventory[i] = NULL;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& oth) {
	if (this != &oth)
		for (int i = 0; i < 4; ++i) {
			delete m_inventory[i];
			if (oth.m_inventory[i])
				m_inventory[i] = oth.m_inventory[i]->clone();
			else
				m_inventory[i] = NULL;
		}
	return *this;
}

void	MateriaSource::learnMateria(AMateria* elem) {
	if (!elem)
		return ;
	for (int i = 0; i < 4; ++i)
		if (!m_inventory[i]) {
			m_inventory[i] = elem;
			return ;
		}
	delete elem;
}

AMateria*	MateriaSource::createMateria(const std::string& type) {
	for (int i = 0; i < 4; ++i)
		if (m_inventory[i] && m_inventory[i]->getType() == type)
			return m_inventory[i]->clone();
	return NULL;
}
