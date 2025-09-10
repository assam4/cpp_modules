# include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("undefined") {
	std::cout << "WrongAnimal: default ctor called!.\n";
}

WrongAnimal::WrongAnimal(const std::string& t): type(t) {
	std::cout << "WrongAnimal: ctor with params called!.\n";
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal: dtor called!.\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& oth): type(oth.type) {
	std::cout << "WrongAnimal: copy ctor called!.\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& oth) {
	std::cout << "WrongAnimal: operator assignment called!.\n";
	if (this != &oth) 
		type = oth.type;
	return *this;
}

std::string	WrongAnimal::getType() const {
	return type;
}

void WrongAnimal::makeSound() const {
	std::cout << "This wrong class cant make sound!.\n";
}	
