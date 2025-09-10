#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat") {
	std::cout << "WrongCat: default ctor called!.\n";
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat: dtor called!.\n";
}

WrongCat::WrongCat(const WrongCat& oth): WrongAnimal(oth) {
	std::cout << "WrongCat: copy ctor called!.\n";
}

WrongCat&	WrongCat::operator=(const WrongCat& oth) {
	WrongAnimal::operator=(oth);
	std::cout << "WrongCat: operator assignment called!.\n";
	return *this;
}

void	WrongCat::makeSound() const {
	std::cout << "Meow@x@X@X!\n";
}
