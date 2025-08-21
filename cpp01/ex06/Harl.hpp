#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

class Harl {
	public:
		Harl();
		~Harl();
	public:
		void	complain(std::string);
	private:
		void	debug();
		void	info();
		void	warning();
		void	error();
		Harl(const Harl&);
		Harl&	operator=(const Harl&);
	private:
		std::string	m_levels[4];
		void		(Harl::*m_p[4])();
};

#endif
