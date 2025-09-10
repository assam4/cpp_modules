# include "AAnimal.hpp"

AAnimal::AAnimal(): type("undefined") {
	std::cout << "AAnimal: default ctor called!.\n";
}

AAnimal::AAnimal(const std::string& t): type(t) {
	std::cout << "AAnimal: ctor with params called!.\n";
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal: dtor called!.\n";
}

AAnimal::AAnimal(const AAnimal& oth): type(oth.type) {
	std::cout << "AAnimal: copy ctor called!.\n";
}

AAnimal& AAnimal::operator=(const AAnimal& oth) {
	std::cout << "AAnimal: operator assignment called!.\n";
	if (this != &oth) 
		type = oth.type;
	return *this;
}

std::string	AAnimal::getType() const {
	return type;
}
