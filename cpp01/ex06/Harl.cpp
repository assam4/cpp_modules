#include "Harl.hpp"

Harl::Harl() {
	this->m_p[0] = &Harl::debug;
	this->m_p[1] = &Harl::info;
	this->m_p[2] = &Harl::warning;
	this->m_p[3] = &Harl::error;
	this->m_levels[0] = "DEBUG";
	this->m_levels[1] = "INFO";
	this->m_levels[2] = "WARNING";
	this->m_levels[3] = "ERROR";
}

Harl::~Harl() {
}

void	Harl::complain(std::string key) {
	bool print_bit = false;

	for (int i = 0; i < 4; ++i) {
		if (this->m_levels[i] == key)
			print_bit = true;
		if (print_bit) {
			(this->*m_p[i])();
			std::cout << std::endl;
		}
	}
	if (!print_bit)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void	Harl::debug() {
	std::cout << "[ DEBUG]\nI love having extra bacon for my"
		" 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info() {
	std::cout  << "[ INFO ]\nI cannot believe adding extra bacon costs more money."
		"You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning() {
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI’ve been"
		" coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error() {
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}
