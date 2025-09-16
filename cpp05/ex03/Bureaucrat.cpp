#include "Bureaucrat.hpp"
#include "AForm.hpp"

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

Bureaucrat::Bureaucrat(): m_name("Unnamed"), m_grade(150) {
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string& name, int grade): m_name(name) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	m_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& oth): m_name(oth.m_name), m_grade(oth.m_grade) {
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& oth) {
	if (this != &oth) {
		m_grade = oth.m_grade;
	}
	return *this;
}

const std::string&	Bureaucrat::getName() const {
	return m_name;
}

int	Bureaucrat::getGrade() const {
	return m_grade;
}

void	Bureaucrat::increment() {
	if (m_grade == 1)
		throw GradeTooHighException();
	--m_grade;
}

void	Bureaucrat::decrement() {
	if (m_grade == 150)
		throw GradeTooLowException();
	++m_grade;
}

void	Bureaucrat::signForm(AForm& form) const {
	try {
		form.beSigned(*this);
		std::cout << m_name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << m_name << " couldn't sign " << form.getName()
			<< " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm& form) const {
	try {
		form.execute(*this);
		std::cout << m_name << " executed " << form.getName() << "\n";
	}
	catch(std::ios_base::failure& e) {
		std::cout << e.what() << std::endl;
	}
	catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& current) {
   os << current.getName() << ", bureaucrat grade " << current.getGrade() << ".";
   return os;
}
