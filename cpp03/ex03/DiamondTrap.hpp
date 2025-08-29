#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {
	public:
		DiamondTrap();
		DiamondTrap(const std::string&);
		DiamondTrap(const DiamondTrap&);
		~DiamondTrap();
	public:
		DiamondTrap&	operator=(const DiamondTrap&);
	public:
		void	attack(const std::string&);
		void	whoAmI();
	private:
		std::string	m_name;
};

#endif
