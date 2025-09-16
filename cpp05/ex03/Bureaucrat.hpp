#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class AForm;

class	Bureaucrat {
	public:
		class	GradeTooHighException: public std::exception {
			public:
				// override
				const char*	what() const throw();
		};

		class	GradeTooLowException: public std::exception {
			public:
				// override
				const char*	what() const throw();
		};
		Bureaucrat();
		Bureaucrat(const std::string&, int);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat&);
		Bureaucrat&	operator=(const Bureaucrat&);
	public:
		const std::string&	getName() const;
		int					getGrade() const;
		void				increment();
		void				decrement();
		void				signForm(AForm&) const;
		void				executeForm(const AForm&) const;
	private:
		const std::string	m_name;
		int					m_grade;
};

std::ostream&	operator<<(std::ostream&, const Bureaucrat&);

#endif
