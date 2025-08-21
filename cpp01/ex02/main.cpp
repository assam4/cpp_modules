#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>

static const std::string	Text = "HI THIS IS BRAIN";
static const std::string	Addr = "Address\n";
static const std::string	Val = "Value\n";
static const std::string	By_value = "Value :";
static const std::string	By_pointer = "Pointer: ";
static const std::string	By_reference = "Reference: ";
static const int			Width = 20;

int main() {
	const std::string* const stringPTR = &Text;
	const std::string& stringREF = Text;

	std::cout << std::left << std::setfill(' ');
	std::cout << Addr 
				<< std::setw(Width) << By_value << std::setw(Width) << &Text << '\n'
				<< std::setw(Width) << By_pointer << std::setw(Width) << stringPTR << '\n'
				<< std::setw(Width) << By_reference << std::setw(Width) << &stringREF << std::endl;
	std::cout << '\n' << Val
				<< std::setw(Width) << By_value << std::setw(Width) << Text << '\n'
				<< std::setw(Width) << By_pointer << std::setw(Width) << *stringPTR << '\n'
				<< std::setw(Width) << By_reference << std::setw(Width) << stringREF << std::endl;
	std::cout.flags(std::ios::fmtflags(0));
	return EXIT_SUCCESS;
}
