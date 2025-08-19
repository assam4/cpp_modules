#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <cstdlib>

class Zombie {
	public:
		Zombie();
		~Zombie();
	public:
		void	announce() const;
		bool	set_name(const std::string&);
	private:
		Zombie(const Zombie&);
		Zombie&	operator=(const Zombie&);
	private:
		std::string	name;
};

Zombie*	zombieHorde(int, std::string);

#endif
