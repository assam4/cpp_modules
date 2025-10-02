#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>

class	RPN {
	public:
		RPN();
		~RPN();
		RPN(const RPN&);
		RPN&	operator=(const RPN&);
		int		operator()(const std::string&);
	private:
		std::stack<int>	m_data;
};

#endif
