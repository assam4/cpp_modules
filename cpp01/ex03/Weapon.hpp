#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

extern const std::string Attack;

class Weapon {
	public:
		Weapon();
		Weapon(const std::string&);
		Weapon(const Weapon&);
		Weapon& operator=(const Weapon&);
		~Weapon();
	public:
		const std::string&	getType() const;
		void				setType(const std::string&);
	private:
			std::string type;
};

#endif 
