#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain: default ctor called!.\n";
}

Brain::~Brain() {
	std::cout << "Brain: dtor called!.\n";
}

Brain::Brain(const Brain& oth) {
	std::cout << "Brain: copy ctor called!.\n";
	for (int i = 0; i < 100; ++i)
		m_ideas[i] = oth.m_ideas[i];
}

Brain&	Brain::operator=(const Brain& oth) {
	std::cout << "Brain: operator assignment called!.\n";
	if (this != &oth)
		for (int i = 0; i < 100; ++i)
			m_ideas[i] = oth.m_ideas[i];
	return *this;
}
