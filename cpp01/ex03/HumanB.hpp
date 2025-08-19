#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB {
	public:
		HumanB(const std::string&);
		~HumanB();
	public:
		void	setWeapon(const Weapon&);
		void	attack() const;
	private:
		HumanB(const HumanB&);
		HumanB&	operator=(const HumanB&);
	private:
		std::string		m_name;
		const Weapon	*m_weapon;
};

#endif
