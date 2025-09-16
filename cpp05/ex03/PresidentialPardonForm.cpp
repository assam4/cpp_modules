#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5) , m_target("Unnamed") {
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& t)
	: AForm("PresidentialPardonForm", 25, 5) , m_target(t) {
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& oth)
	: AForm(oth), m_target(oth.m_target) {
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& oth) {
	if (this != &oth) {
		AForm::operator=(oth);
		m_target = oth.m_target;
	}
	return *this;
}

void	PresidentialPardonForm::execute(const Bureaucrat& bur) const {
	if (!getSigned())
		throw AForm::FormNotSignedException();
	if (bur.getGrade() > getGradeExecute())
		throw AForm::GradeTooLowException();
	std::cout << m_target << " has been pardoned by Zaphod Beeblebrox!";
};
