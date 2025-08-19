#include "Zombie.hpp"

Zombie*	zombieHorde(int n, std::string name) {
	Zombie *arr = new Zombie[n];
	for (int i = 0; i < n; ++i)
		if (!arr[i].set_name(name)) {
			delete [] arr;
			return NULL;
		}
	return arr;
}
