#include "Form.hpp"
#include "Bureaucrat.hpp"

const char*	Form::GradeTooHighException::what() const throw() {
	return "Form grade is too high!";
}

const char*	Form::GradeTooLowException::what() const throw() {
	return "Form grade is too low!";
}

Form::Form(): m_name("Unnamed"), m_signed(false), m_gradeToSign(150), m_gradeToExecute(150) {
}

Form::Form(const std::string& n, int s, int e)
	: m_name(n), m_signed(false), m_gradeToSign(s), m_gradeToExecute(e) {
	if (m_gradeToSign < 1 || m_gradeToExecute < 1) throw Form::GradeTooHighException();
	if (m_gradeToSign > 150 || m_gradeToExecute > 150) throw Form::GradeTooLowException();
}

Form::~Form() {
}

Form::Form(const Form& oth)
	: m_name(oth.m_name), m_signed(oth.m_signed)
	  , m_gradeToSign(oth.m_gradeToSign) , m_gradeToExecute(oth.m_gradeToExecute) {
}


Form&	Form::operator=(const Form& oth) {
	if (this != &oth)
		m_signed = oth.m_signed;
	return *this;
}

std::string	Form::getName() const {
	return m_name;
}

bool	Form::getSigned() const {
	return m_signed;
}

int	Form::getGradeSign() const {
	return m_gradeToSign;
}

int Form::getGradeExecute() const {
	return m_gradeToExecute;
}

void	Form::beSigned(const Bureaucrat& current) {
	if (current.getGrade() > m_gradeToSign) throw Form::GradeTooLowException();
	m_signed = true;
}

std::ostream&	operator<<(std::ostream& os, const Form& curr) {
	os << "Form " << curr.getName() << " [sign grade: " << curr.getGradeSign()
		<< ", execute grade: " << curr.getGradeExecute() << ", signed: "
		<< (curr.getSigned() ? "yes" : "no") << "]";
	return os;
}
