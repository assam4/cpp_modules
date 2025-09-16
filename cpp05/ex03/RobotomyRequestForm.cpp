#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45) , m_target("Unnamed") {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& t)
	: AForm("RobotomyRequestForm", 72, 45) , m_target(t) {
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& oth)
	: AForm(oth), m_target(oth.m_target) {
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& oth) {
	if (this != &oth) {
		AForm::operator=(oth);
		m_target = oth.m_target;
	}
	return *this;
}

void	RobotomyRequestForm::execute(const Bureaucrat& bur) const {
	if (!getSigned())
		throw AForm::FormNotSignedException();
	if (bur.getGrade() > getGradeExecute())
		throw AForm::GradeTooLowException();
	std::cout << "Bzzzzzzzzzzzzzzz" << std::endl;
	if (!(std::rand() & 1))
		std::cout << m_target << " has been robotomized successfully\n";
	else
		std::cout << "Robotomy failed!\n";
};
