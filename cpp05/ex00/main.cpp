#include <iostream>
#include "Bureaucrat.hpp"

int main() {
	try {
		try {
			Bureaucrat a("Alice", 2);
			std::cout << a << '\n';
			a.increment();
			std::cout << a << '\n';
			a.increment();
			std::cout << a << '\n';
		} 
		catch (std::exception& e) {
			std::cout << "Exception: " << e.what() << '\n';
		}
		try {
			Bureaucrat b("Bob", 150);
			std::cout << b << '\n';
			b.decrement();
			std::cout << b << '\n';
			b.decrement();
			std::cout << b << '\n';
		}
		catch (std::exception& e) {
			std::cout << "Exception: " << e.what() << '\n';
		}
		try {
			Bureaucrat c("Carol", 0);
			std::cout << c << '\n';
		}
		catch (std::exception& e) {
			std::cout << "Exception: " << e.what() << '\n';
		}	
		try {
			Bureaucrat d("Dave", 151);
			std::cout << d << '\n';
		}
		catch (std::exception& e) {
			std::cout << "Exception: " << e.what() << '\n';
		}
		try {
			Bureaucrat e("Eve", 42);
			Bureaucrat f = e;
			std::cout << e << '\n';
			std::cout << f << '\n';
			Bureaucrat g("Ghost", 100);
			g = e;
			std::cout << g << '\n';
		}
		catch (std::exception& ex) {
			std::cout << "Exception: " << ex.what() << '\n';
		}
		return 0;
	}
	catch (...) {
		std::cout << "Undefined error!." << std::endl;
		return 1;
	}
}

