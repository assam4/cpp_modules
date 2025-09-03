#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(const std::string&);
		virtual ~WrongAnimal();
		WrongAnimal(const WrongAnimal&);
		WrongAnimal& operator=(const WrongAnimal&);
	public:
		void makeSound() const;
		std::string	getType() const;
	protected:
		std::string type;
};

#endif
