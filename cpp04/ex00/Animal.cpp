# include "Animal.hpp"

Animal::Animal(): type("undefined") {
	std::cout << "Animal: default ctor called!.\n";
}

Animal::Animal(const std::string& t): type(t) {
	std::cout << "Animal: ctor with params called!.\n";
}

Animal::~Animal() {
	std::cout << "Animal: dtor called!.\n";
}

Animal::Animal(const Animal& oth): type(oth.type) {
	std::cout << "Animal: copy ctor called!.\n";
}

Animal& Animal::operator=(const Animal& oth) {
	std::cout << "Animal: operator assignment called!.\n";
	if (this != &oth) 
		type = oth.type;
	return *this;
}

std::string	Animal::getType() const {
	return type;
}

void Animal::makeSound() const {
	std::cout << "This class cant make sound!.\n";
}	
