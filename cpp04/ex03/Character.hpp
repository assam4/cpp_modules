#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class	Character: public ICharacter {
	public:
		Character();
		Character(const std::string&);
		~Character();
		Character(const Character&);
		Character&	operator=(const Character&);
	public:
		const std::string&	getName() const;
		void	equip(AMateria*);
		void	unequip(int);
		void	use(int, ICharacter&);
	private:
		std::string	m_name;
		AMateria*	m_inventory[4];
};

#endif	
