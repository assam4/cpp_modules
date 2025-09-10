#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"

class	Cat: public AAnimal {
	public:
		Cat();
		~Cat();
		Cat(const Cat&);
		Cat&	operator=(const Cat&);
	public:
		void	makeSound() const;
	private:
		Brain*	m_attribute;
};

#endif
