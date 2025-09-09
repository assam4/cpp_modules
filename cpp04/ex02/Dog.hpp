#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"

class Dog: public AAnimal {
	public:
		Dog();
		~Dog();
		Dog(const Dog&);
		Dog& operator=(const Dog&);
	public:
		void makeSound() const;
	private:
		Brain*	m_attribute;
};

#endif
