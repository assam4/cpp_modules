#ifndef STRINGREPLACE_HPP
# define STRINGREPLACE_HPP

# include <string>

class StringReplace {
	public:
		std::string	operator()(const std::string& source) const;
		void		set(const std::string&, const std::string&);
		bool		empty() const;
	private:
		std::string	m_search;
		std::string	m_replace;
};

#endif
