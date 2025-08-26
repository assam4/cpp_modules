#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	public:
		Fixed();
		Fixed(const Fixed&);
		~Fixed();
	public:
		Fixed&	operator=(const Fixed&);
	public:
		int		getRawBits() const;
		void	setRawBits(int const raw);
	private:
		int					m_value;
		const static int	m_fractionalBits;
};

#endif
