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
	public:
		float	toFloat() const;
		int		toInt() const;
	private:
		int					m_value;
		const static int	m_fractionalBits;
};


std::ostream&	operator<<(std::ostream&, const Fixed&);

#endif
