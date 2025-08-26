#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	public:
		Fixed();
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed&);
		~Fixed();
	public:
		Fixed&	operator=(const Fixed&);
		bool	operator>(const Fixed&) const;
		bool	operator<(const Fixed&) const;
		bool	operator>=(const Fixed&) const;
		bool	operator<=(const Fixed&) const;
		bool	operator==(const Fixed&) const;
		bool	operator!=(const Fixed&) const;
		Fixed	operator+(const Fixed&) const;
		Fixed	operator-(const Fixed&) const;
		Fixed	operator*(const Fixed&) const;
		Fixed	operator/(const Fixed&) const;
		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);
	public:
		float	toFloat() const;
		int		toInt() const;
	public:
		static Fixed&		min(Fixed&, Fixed&);
		static const Fixed&	min(const Fixed&, const Fixed&);
		static Fixed&		max(Fixed&, Fixed&);
		static const Fixed&	max(const Fixed&, const Fixed&);
	private:
		int					m_value;
		const static int	m_fractionalBits;
};


std::ostream&	operator<<(std::ostream&, const Fixed&);

#endif
