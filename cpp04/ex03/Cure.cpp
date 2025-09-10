#include "Cure.hpp"

Cure::Cure(): AMateria("cure") {
}

Cure::~Cure() {
}

Cure::Cure(const Cure& oth): AMateria(oth) {
}

Cure&	Cure::operator=(const Cure& oth) {
	AMateria::operator=(oth);
	return *this;
}

AMateria*	Cure::clone() const {
	return new Cure(*this);
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "’s wounds *\n";
}
