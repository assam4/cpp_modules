#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <cstdlib>

class Zombie {
	public:
		Zombie(const std::string&);
		~Zombie();
	public:
		void	announce(void);
	private:
		Zombie(const Zombie&);
		Zombie&	operator=(const Zombie&);
	private:
		std::string	name;
};

Zombie*	newZombie(std::string);
void	randomChump(std::string);

#endif
