#include "Fixed.hpp"

const int Fixed::m_fractionalBits = 8;

Fixed::Fixed(): m_value(0) {
}

Fixed::Fixed(const float value)
	: m_value(static_cast<int>(roundf(value * (1 << m_fractionalBits)))) {
}

Fixed::Fixed(const int value): m_value(value << m_fractionalBits) {
}

Fixed::Fixed(const Fixed& other): m_value(other.m_value) {
}

Fixed::~Fixed() {
}

Fixed&	Fixed::operator=(const Fixed& other) {
	if (this != &other)
		this->m_value = other.m_value;
	return *this;
}

bool	Fixed::operator>(const Fixed& oth) const {
	return m_value > oth.m_value;
}

bool	Fixed::operator<(const Fixed& oth) const {
	return m_value < oth.m_value;
}

bool	Fixed::operator>=(const Fixed& oth) const {
	return m_value >= oth.m_value;
}

bool	Fixed::operator<=(const Fixed& oth) const {
	return m_value <= oth.m_value;
}

bool	Fixed::operator==(const Fixed& oth) const {
	return m_value == oth.m_value;
}

bool	Fixed::operator!=(const Fixed& oth) const {
	return m_value != oth.m_value;
}

Fixed	Fixed::operator+(const Fixed& oth) const {
	return Fixed(m_value + oth.m_value);
}

Fixed	Fixed::operator-(const Fixed& oth) const {
	return Fixed(m_value - oth.m_value);
}

Fixed	Fixed::operator*(const Fixed& oth) const {
	return Fixed(toFloat() * oth.toFloat());
}

Fixed	Fixed::operator/(const Fixed& oth) const {
	return Fixed(toFloat() / oth.toFloat());
}

Fixed&	Fixed::operator++() {
	++m_value;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed	temp(*this);
	++m_value;
	return temp;
}

Fixed&	Fixed::operator--() {
	--m_value;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed	temp(*this);
	--m_value;
	return temp;
}

Fixed&	Fixed::min(Fixed& l, Fixed& r) {
	return l < r ? l : r;
}

const Fixed&	Fixed::min(const Fixed& l, const Fixed& r) {
	return l < r ? l : r;
}

Fixed&	Fixed::max(Fixed& l, Fixed& r) {
	return l > r ? l : r;
}

const Fixed&	Fixed::max(const Fixed& l, const Fixed& r) {
	return l > r ? l : r;
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
