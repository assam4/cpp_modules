#include "AMateria.hpp"

AMateria::AMateria(): m_type("Undefined") {
}

AMateria::AMateria(const std::string& type): m_type(type) {
}

AMateria::~AMateria() {
}

AMateria::AMateria(const AMateria& oth): m_type(oth.m_type) {
}

AMateria&	AMateria::operator=(const AMateria& oth) {
	if (this != &oth)
		m_type = oth.m_type;
	return *this;
}

const std::string&	AMateria::getType() const {
	return m_type;
}

void	AMateria::use(ICharacter&) { }
