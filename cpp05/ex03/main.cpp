#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    std::srand(std::time(0));
    try {
        Bureaucrat bob("Bob", 50);
        Bureaucrat jim("Jim", 140);
        Intern someIntern;
        std::cout << bob << std::endl;
        std::cout << jim << std::endl;
        AForm* f1 = someIntern.makeForm("shrubbery creation", "home");
        AForm* f2 = someIntern.makeForm("robotomy request", "Bender");
        AForm* f3 = someIntern.makeForm("presidential pardon", "Marvin");
        std::cout << *f1 << std::endl;
        std::cout << *f2 << std::endl;
        std::cout << *f3 << std::endl;
        jim.signForm(*f1);   
        bob.signForm(*f1);
        bob.signForm(*f2);
        bob.signForm(*f3);
        jim.executeForm(*f1);
        bob.executeForm(*f1);
        bob.executeForm(*f2);
        bob.executeForm(*f3);
        delete f1;
        delete f2;
        delete f3;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

