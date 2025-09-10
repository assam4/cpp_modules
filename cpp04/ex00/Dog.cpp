#include "Dog.hpp"

Dog::Dog(): Animal("Dog") {
	std::cout << "Dog: default ctor called!.\n";
}

Dog::~Dog() {
	std::cout << "Dog: dtor called!.\n";
}

Dog::Dog(const Dog& oth): Animal(oth) {
	std::cout << "Dog: copy ctor called!.\n";
}

Dog&	Dog::operator=(const Dog& oth) {
	Animal::operator=(oth);
	std::cout << "Dog: operator assignment called!.\n";

	return *this;
}

void	Dog::makeSound() const {
	std::cout << "Woof Woof!.\n";
}
