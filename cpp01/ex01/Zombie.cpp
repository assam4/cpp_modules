#include "Zombie.hpp"

static const char	*Separator = ": ";
static const char	*Dtor_str = "destroyed!";
static const char	*Brainz_str = "BraiiiiiiinnnzzzZ...";

Zombie::Zombie() {
}

Zombie::~Zombie() {
	std::cout << this->name << Separator << Dtor_str << std::endl;
}

void	Zombie::announce() const {
	std::cout << this->name << Separator << Brainz_str << std::endl;
}

bool	Zombie::set_name(const std::string& newName) {
	try {
		this->name = newName;
		return true;
	}
	catch (const std::bad_alloc& e) {
		std::cerr << e.what() << std::endl;
		return false;
	}
	catch (...) {
		return false;
	}
}
