#include "Cat.hpp"

Cat::Cat(): Animal("Cat") {
	std::cout << "Cat: default ctor called\n";
}

Cat::~Cat() {
	std::cout << "Cat: dtor called\n";
}

Cat::Cat(const Cat& oth): Animal(oth) {
	std::cout << "Cat: copy ctor called!\n";
}

Cat&	Cat::operator=(const Cat& oth) {
	std::cout << "Cat: operator assignment called!\n";
	Animal::operator=(oth);
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "Meow Meow!\n";
}
