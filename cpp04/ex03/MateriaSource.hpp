#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class	MateriaSource: public IMateriaSource {
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource&);
		MateriaSource&	operator=(const MateriaSource&);
	public:
		void	learnMateria(AMateria*);
		AMateria*	createMateria(const std::string&);

	private:
		AMateria*	m_inventory[4];
};

#endif
