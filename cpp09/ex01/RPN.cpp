#include "RPN.hpp"
#include <stdexcept>

RPN::RPN() {
}

RPN::~RPN() {
}

RPN::RPN(const RPN& oth) : m_data(oth.m_data) {
}

RPN&	RPN::operator=(const RPN& oth) {
	if (this != &oth)
		m_data = oth.m_data;
	return *this;
}

int	RPN::operator()(const std::string& expression) {
	for (size_t i = 0; i < expression.length(); ++i) {
		switch (expression[i]) {
			case ' ':
				break ;
			case '0' : case '1' : case '2' : case '3' : case '4' :
			case '5' : case '6' : case '7' : case '8' : case '9' :
				m_data.push(expression[i] - '0');
				break ;
			case '-' : case '+' :
				{
					if (m_data.size() < 2)
						throw std::runtime_error("Error");
					int	right = m_data.top();
					m_data.pop();
					int	result = m_data.top() + ((expression[i] == '+') ? right : - right); 
					m_data.pop();
					m_data.push(result);
					break ;
				}
			case '*' :
				{
					if (m_data.size() < 2)
						throw std::runtime_error("Error");
					int	right = m_data.top();
					m_data.pop();
					int result = m_data.top() * right;
					m_data.pop();
					m_data.push(result);
					break ;
				}
			case '/' :
				{
					if (m_data.size() < 2)
						throw std::runtime_error("Error");
					int right = m_data.top();
					m_data.pop();
					if (right == 0)
						throw std::runtime_error("Divizion by Zero!");
					int result = m_data.top() / right;
					m_data.pop();
					m_data.push(result);
					break ;
				}
			default:
				throw std::runtime_error("Error");
		}
	}
	if (m_data.size() != 1)
		throw std::runtime_error("Error");
	return m_data.top();
}
