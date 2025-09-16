#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class	RobotomyRequestForm: public AForm {
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string&);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm&);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm&);
	public:
		void	execute(const Bureaucrat& executor) const;
	private:
		std::string	m_target;
};

#endif
