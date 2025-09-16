#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <exception>

class Bureaucrat;

class AForm {
	public:
		class	GradeTooHighException: public std::exception {
			public:
				const char* what() const throw();
		};
		class	GradeTooLowException: public std::exception {
			public:
				const char* what() const throw();
		};
		class	FormNotSignedException: public std::exception {
			public:
				const char*	what() const throw();
		};
	public:
		AForm();
		AForm(const std::string&, int, int);
		virtual ~AForm();
		AForm(const AForm&);
		AForm&	operator=(const AForm&);
	public:
		virtual void	execute(const Bureaucrat&) const = 0;
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

std::ostream&	operator<<(std::ostream&, const AForm&);

#endif
