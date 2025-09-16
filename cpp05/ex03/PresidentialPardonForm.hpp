#ifndef PRESIDENTIALPARDON_HPP
# define PRESIDENTIALPARDON_HPP

# include "AForm.hpp"

class	PresidentialPardonForm: public AForm {
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string&);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm&);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm&);
	public:
		void	execute(const Bureaucrat& executor) const;
	private:
		std::string	m_target;
};

#endif
