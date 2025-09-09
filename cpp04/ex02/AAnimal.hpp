#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include "Brain.hpp"

class AAnimal {
	public:
		AAnimal();
		AAnimal(const std::string&);
		virtual ~AAnimal();
		AAnimal(const AAnimal&);
		AAnimal& operator=(const AAnimal&);
	public:
		virtual void makeSound() const = 0;
		std::string	getType() const;
	protected:
		std::string type;
};

#endif
