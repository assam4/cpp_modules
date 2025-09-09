#include "Cat.hpp"

Cat::Cat(): Animal("Cat") {
	try {
		m_attribute = new Brain;
	}
	catch (...) {
		std::cout << "Allocation failed!.\n";
		m_attribute = NULL;
	}
	std::cout << "Cat: default ctor called\n";
}

Cat::~Cat() {
	delete m_attribute;
	std::cout << "Cat: dtor called\n";
}

Cat::Cat(const Cat& oth): Animal(oth) {
	try {
		m_attribute = new Brain(*oth.m_attribute);
	}
	catch (...) {
		std::cout << "Allocation failed!.\n";
		m_attribute = NULL;
	};
	std::cout << "Cat: copy ctor called!\n";
}

Cat&	Cat::operator=(const Cat& oth) {
	std::cout << "Cat: operator assignment called!\n";
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

void	Cat::makeSound() const {
	std::cout << "Meow Meow!\n";
}
