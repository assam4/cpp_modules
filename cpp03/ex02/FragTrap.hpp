#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
	public:
		FragTrap();
		FragTrap(const std::string& name);
		FragTrap(const FragTrap&);
		~FragTrap();
	public:
		FragTrap&	operator=(const FragTrap&);
	public:
		void		highFivesGuys();
};

#endif
