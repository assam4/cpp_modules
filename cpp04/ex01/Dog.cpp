#include "Dog.hpp"

Dog::Dog(): Animal("Dog") {
	try {
		m_attribute = new Brain;
	}
	catch (...) {
		std::cout << "Allocation failed!.\n";
		m_attribute = NULL;
	}
	std::cout << "Dog: default ctor called!\n";
}

Dog::~Dog() {
	delete m_attribute;
	std::cout << "Dog: dtor called!\n";
}

Dog::Dog(const Dog& oth): Animal(oth) {
	try {
		m_attribute = new Brain(*oth.m_attribute);
	}
	catch (...) {
		std::cout << "Allocation failed!.\n";
		m_attribute = NULL;
	}
	std::cout << "Dog: copy ctor called!\n";
}

Dog&	Dog::operator=(const Dog& oth) {
	std::cout << "Dog: operator assignment called!\n";
	Animal::operator=(oth);
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
	std::cout << "Woof woof\n";
}
