#include "Fixed.hpp"

const int Fixed::m_fractionalBits = 8;

Fixed::Fixed(): m_value(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& other): m_value(other.m_value) {
	std::cout << "Copy constructor called\n";
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

Fixed&	Fixed::operator=(const Fixed& other) {
	if (this != &other)
		this->m_value = other.m_value;
	std::cout << "Copy assignment operator called\n";
	return *this;
}

int		Fixed::getRawBits() const{
	std::cout << "getRawBits member function called\n";
	return this->m_value;
}

void	Fixed::setRawBits(int const raw) {
	this->m_value = raw;
	std::cout << "setRawBits member function called\n";
}
