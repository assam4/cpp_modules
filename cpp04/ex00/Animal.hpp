#ifndef Animal_HPP
# define Animal_HPP

# include <iostream>
# include <string>

class	Animal {
	public:
		Animal();
		Animal(const std::string&);
		virtual ~Animal();
		Animal(const Animal&);
		Animal& operator=(const Animal&);
	public:
		virtual void makeSound() const;
		std::string	getType() const;
	protected:
		std::string type;
};

#endif
