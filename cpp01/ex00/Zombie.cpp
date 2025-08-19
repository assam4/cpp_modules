#include "Zombie.hpp"

//static const char	*Zombie_str = "Zombie";
//static const char	*Ctor_str = "created!";
static const char	*Separator = ": ";
static const char	*Dtor_str = "destroyed!";
static const char	*Brainz_str = "BraiiiiiiinnnzzzZ...";

Zombie::~Zombie() {
	std::cout << this->name << Separator << Dtor_str << std::endl;
}

Zombie::Zombie(const std::string& name) {
	this->name = name;
}

void	Zombie::announce() {
	std::cout << this->name << Separator << Brainz_str << std::endl;
}
