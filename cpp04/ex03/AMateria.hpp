#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class	ICharacter;

class	AMateria {
	public:
		AMateria();
		AMateria(const std::string&);
		virtual ~AMateria();
		AMateria(const AMateria&);
		AMateria&	operator=(const AMateria&);
	public:
		const std::string&	getType() const;
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter&);
	protected:
		std::string	m_type;
};

#endif
