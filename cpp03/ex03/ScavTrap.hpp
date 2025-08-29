#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap&);
		~ScavTrap(); // override
	public:
		ScavTrap&	operator=(const ScavTrap&);
	public:
		void		attack(const std::string& name); // override
		void		guardGate();
};

#endif
