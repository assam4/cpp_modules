#include "Dog.hpp"

Dog::Dog(): AAnimal("Dog") {
	try {
		m_attribute = new Brain;
	}
	catch (...) {
		std::cout << "Allocation failed!.\n";
		m_attribute = NULL;
	}
	std::cout << "Dog: default ctor called!.\n";
}

Dog::~Dog() {
	delete m_attribute;
	std::cout << "Dog: dtor called!.\n";
}

Dog::Dog(const Dog& oth): AAnimal(oth) {
	try {
		m_attribute = new Brain(*oth.m_attribute);
	}
	catch (...) {
		std::cout << "Allocation failed!.\n";
		m_attribute = NULL;
	}
	std::cout << "Dog: copy ctor called!.\n";
}

Dog&	Dog::operator=(const Dog& oth) {
	AAnimal::operator=(oth);
	std::cout << "Dog: operator assignment called!.\n";
	if (this != &oth) {
		delete m_attribute;
		try {
			m_attribute = new Brain(*oth.m_attribute);
		}
		catch (...) {
			std::cout << "Allocation failed!.\n";
			m_attribute = NULL;
		}
	}
	return *this;
}

void	Dog::makeSound() const {
	std::cout << "Woof Woof!\n";
}
