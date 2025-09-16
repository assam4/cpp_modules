#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char*	AForm::GradeTooHighException::what() const throw() {
	return "Form grade is too high!";
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return "Form grade is too low!";
}

const char*	AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed!";
}

AForm::AForm(): m_name("Unnamed"), m_signed(false), m_gradeToSign(150), m_gradeToExecute(150) {
}

AForm::AForm(const std::string& n, int s, int e)
	: m_name(n), m_signed(false), m_gradeToSign(s), m_gradeToExecute(e) {
	if (m_gradeToSign < 1 || m_gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (m_gradeToSign > 150 || m_gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm() {
}

AForm::AForm(const AForm& oth)
	: m_name(oth.m_name), m_signed(oth.m_signed)
	  , m_gradeToSign(oth.m_gradeToSign) , m_gradeToExecute(oth.m_gradeToExecute) {
}


AForm&	AForm::operator=(const AForm& oth) {
	if (this != &oth)
		m_signed = oth.m_signed;
	return *this;
}

std::string	AForm::getName() const {
	return m_name;
}

bool	AForm::getSigned() const {
	return m_signed;
}

int	AForm::getGradeSign() const {
	return m_gradeToSign;
}

int AForm::getGradeExecute() const {
	return m_gradeToExecute;
}

void	AForm::beSigned(const Bureaucrat& current) {
	if (current.getGrade() > m_gradeToSign)
		throw AForm::GradeTooLowException();
	m_signed = true;
}

std::ostream&	operator<<(std::ostream& os, const AForm& curr) {
	os << "AForm " << curr.getName() << " [sign grade: " << curr.getGradeSign()
		<< ", execute grade: " << curr.getGradeExecute() << ", signed: "
		<< (curr.getSigned() ? "yes" : "no") << "]";
	return os;
}
