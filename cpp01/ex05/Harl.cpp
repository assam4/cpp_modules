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
	for (int i = 0; i < 4; ++i)
		if (this->m_levels[i] == key)
			(this->*m_p[i])();
}

void	Harl::debug() {
	std::cout << "[ DEBUG] I love having extra bacon for my"
		" 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info() {
	std::cout  << "[ INFO ] I cannot believe adding extra bacon costs more money."
		"You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning() {
	std::cout << "[ WARNING ] I think I deserve to have some extra bacon for free. I’ve been"
		" coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error() {
	std::cout << "[ ERROR ] This is unacceptable! I want to speak to the manager now." << std::endl;
}
