#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>

class AForm;

class Intern {
	public:
		Intern();
		~Intern();
		Intern(const Intern&);
		Intern& operator=(const Intern&);
	public:
		AForm*	makeForm(const std::string&, const std::string&) const;
	private:
		AForm*	createShrubbery(const std::string&) const;
		AForm*	createRobotomy(const std::string&) const;
		AForm*	createPresidental(const std::string&) const;
};

#endif
