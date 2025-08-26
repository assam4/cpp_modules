#include "Fixed.hpp"

const int Fixed::m_fractionalBits = 8;

Fixed::Fixed(): m_value(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const float value)
	: m_value(static_cast<int>(roundf(value * (1 << m_fractionalBits)))) {
		std::cout << "Float constructor called\n";
}

Fixed::Fixed(const int value): m_value(value << m_fractionalBits) {
	std::cout << "Int constructor called\n";
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

float	Fixed::toFloat() const {
	return static_cast<float>(m_value) / (1 << m_fractionalBits);
}

int		Fixed::toInt() const {
	return (m_value >> m_fractionalBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& obj) {
	out << obj.toFloat();
	return out;
}
