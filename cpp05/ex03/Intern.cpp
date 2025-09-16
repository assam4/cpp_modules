#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {
}

Intern::~Intern() {
}

Intern::Intern(const Intern&) {
}

Intern& Intern::operator=(const Intern&) {
	return *this;
}

AForm*	Intern::makeForm(const std::string& form, const std::string& name) const {
	struct Pair {
		const std::string	name;
		AForm*	(Intern::*creater)(const std::string&) const;
	};
	static const	Pair forms[] = {
		{ "shrubbery creation", &Intern::createShrubbery },
		{ "robotomy request", &Intern::createRobotomy },
		{ "presidential pardon", &Intern::createPresidental }
	};
	for (int i = 0; i < 3; ++i)
		if (form == forms[i].name) {
			std::cout << "Intern creates " << form << std::endl;
			return (this->*forms[i].creater)(name);
		}
	std::cout << "Intern can't create form: unknown form name '" << form << "'" << std::endl;
	return NULL;
}

AForm*  Intern::createShrubbery(const std::string& name) const {
	return new ShrubberyCreationForm(name);
}

AForm*  Intern::createRobotomy(const std::string& name) const {
	return new RobotomyRequestForm(name);
}

AForm*  Intern::createPresidental(const std::string& name) const {
	return  new PresidentialPardonForm(name);
}
