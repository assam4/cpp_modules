#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat bob("Bob", 50);
        Bureaucrat jim("Jim", 140);
        Form tax("Tax Form", 100, 50);
        Form passport("Passport Form", 30, 10);
        std::cout << bob << std::endl;
        std::cout << jim << std::endl;
        std::cout << tax << std::endl;
        std::cout << passport << std::endl;
        jim.signForm(tax);
        std::cout << tax << std::endl;
        bob.signForm(tax);
        std::cout << tax << std::endl;
        bob.signForm(passport);
    } 
	catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
	catch (...) {
		std::cout << "Unknown Error!" << std::endl;
		return 1;
	}
    return 0;
}

