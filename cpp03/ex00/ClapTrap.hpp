#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <limits>
# include <string>

class ClapTrap {
	public:
		ClapTrap();
		ClapTrap(const std::string& name, unsigned hp = 10, unsigned ep = 10 , unsigned ad = 0);
		ClapTrap(const ClapTrap&);
		~ClapTrap();
	public:
		ClapTrap&	operator=(const ClapTrap&);
	public:
		void	attack(const std::string&);
		void	takeDamage(unsigned);
		void	beRepaired(unsigned);
	private:
		std::string		m_name;
		unsigned		m_hitPoint;
		unsigned		m_energyPoint;
		unsigned		m_damage;
};

#endif
