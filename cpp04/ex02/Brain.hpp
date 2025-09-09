#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain {
	public:
		Brain();
		~Brain();
		Brain(const Brain&);
		Brain& operator=(const Brain&);
	private:
		std::string	m_ideas[100];	
};

#endif
