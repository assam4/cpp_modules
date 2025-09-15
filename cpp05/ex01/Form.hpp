#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <exception>

class Bureaucrat;

class Form {
	public:
		class GradeTooHighException: public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				const char* what() const throw();
		};
	public:
		Form();
		Form(const std::string&, int, int);
		~Form();
		Form(const Form&);
		Form&	operator=(const Form&);
	public:
		std::string	getName() const;
		bool		getSigned() const;
		int			getGradeSign() const;
		int			getGradeExecute() const;
		void		beSigned(const Bureaucrat&);
	private:
		const std::string	m_name;
		bool				m_signed;
		const int			m_gradeToSign;
		const int			m_gradeToExecute;
};

std::ostream&	operator<<(std::ostream&, const Form&);

#endif
