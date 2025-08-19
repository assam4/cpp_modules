#ifndef HUMANA_HHP
# define HUMANA_HHP

# include <iostream>
# include "Weapon.hpp"

class HumanA {
	public:
		HumanA(const std::string&, const Weapon&);
		~HumanA();
	public:
		void	attack() const;
	private:
		HumanA(const HumanA&);
		HumanA& operator=(const HumanA&);
	private:
			std::string			m_name;
			const Weapon		*m_weapon;
};

#endif
