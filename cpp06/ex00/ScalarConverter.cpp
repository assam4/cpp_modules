#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iostream>
#include <limits>
#include <iomanip>

ScalarConverter::ScalarConverter() {
}

ScalarConverter::~ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter&) {
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter&) {
	return *this;
}

static bool	isSpecialLiteral(const std::string& str) {
	size_t	size = str.size();
	if (size >= 3 && size <= 5) {
	char	firstLet = str[0] , lastLet = str[size - 1];
	if (firstLet == 'n' && lastLet == 'f') return str == "nanf";
	if (firstLet == 'n' && lastLet == 'n') return str == "nan";
	if (firstLet == '+' && lastLet == 'f') return ((size == 5) ? str == "+inff" : str == "+inf");
	if (firstLet == '-' && lastLet == 'f') return ((size == 5) ? str == "-inff" : str == "-inf");
	}
	return false;	
}

static bool isSpecialChar(const std::string& str) {
	return (str.size() == 3 && str[0] == '\'' && str[2] == '\'');
}

static bool	isValidNumber(const std::string& str) {
	size_t		i = 0, size = str.size();
	bool	decimal_point = false, sign = false;
	if (size && (str[i] == '-' || str[i] == '+'))
		sign = static_cast<bool>(++i);
	if (!(size - i))
		return false;
	while (i < size) {
		if (str[i] == 'f') {
			if (i != size - 1)
				return false;
		}
		else if (str[i] == '.') {
			if (!i || i == size - 1 || !std::isdigit(str[i + 1]))
				return false;
			if (decimal_point || !(i - static_cast<size_t>(sign) || i == size - 1))
				return false;
			decimal_point = true;
		}
		else if (!std::isdigit(str[i]))
			return false;
		++i;
	}
	return true;
}	
static void	printSpecialLiteral(const std::string& str) {
	std::cout << "char: impossible\n""int: impossible\n";
	switch(str[0]) {
		case 'n': std::cout << "float: nanf\n""double: nan\n"; break;
		case '+': std::cout << "float: +inff\n""double: +inf\n"; break;
		case '-': std::cout << "float: -inff\n""double: -inf\n"; break;
	}
}

static void	printAllTypes(double num, int precNum) {
	bool	intRange = static_cast<double>(std::numeric_limits<int>::max()) >= num
						&& static_cast<double>(std::numeric_limits<int>::min()) <= num;
	bool	floatRange = static_cast<double>(std::numeric_limits<float>::max()) >= num
						&& -static_cast<double>(std::numeric_limits<float>::max()) <= num;
	std::cout << "char: ";
	if (!intRange || num < 0.0 || num > 127.0)
		std::cout << "impossible\n";
	else if (num < 32.0 || num > 126.0)
		std::cout << "Non displayable\n";
	else
		std::cout << "'" << static_cast<char>(num) << "'\n";
	std::cout << "int: ";
	if (intRange)
		std::cout << static_cast<int>(num) << "\n";
	else
		std::cout << "impossible\n";
	std::cout << "float: ";
	if (floatRange)
		std::cout << std::fixed << std::setprecision(precNum)<< static_cast<float>(num) << "f\n";
	else
		std::cout << "impossible\n";
	std::cout << "double: " /*<< std::fixed << std::setprecision(precNum)*/ << num << "\n";
}

static int	getPrecisionNum(const std::string& src) {
	size_t index = src.find('.');
	if (index == std::string::npos)
		return 1;
	else
		return (src.size() - index - 1 - (src[src.size() - 1] == 'f'));
}

void	ScalarConverter::convert(const std::string& text) {
	bool	specialLit = isSpecialLiteral(text);
	bool	specialChar = (specialLit) ? false : isSpecialChar(text);
	bool	number = (specialLit) ? false : ((specialChar) ? true : isValidNumber(text));
	if (specialLit) printSpecialLiteral(text);
	else if (number) {
		double	numberF = (specialChar) ? static_cast<double>(text[1]) : std::atof(text.c_str());
		printAllTypes(numberF, getPrecisionNum(text));
	}
	else
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
}	
