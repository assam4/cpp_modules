#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP

# include "AForm.hpp"

class	ShrubberyCreationForm: public AForm {
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string&);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm&);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm&);
	public:
		void	execute(const Bureaucrat& executor) const;
	private:
		std::string	m_target;
};

#endif
