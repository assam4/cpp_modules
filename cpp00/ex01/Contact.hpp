#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>

extern const int	Start_index;
extern const size_t	Required_length;

class Contact {
	public:
		Contact() {};
		~Contact() {};
		Contact (const std::string& fname, const std::string& lname,
				const std::string& nname, const std::string& pnum,
				const std::string& secret, int index = Start_index);
		Contact& operator= (const Contact& other);
	public:
		const std::string&	get_fname() const;
		const std::string&	get_lname() const;
		const std::string&	get_nname() const;
		const std::string&	get_pnum() const;
		const std::string&	get_secret() const;
		int					get_index() const;
		void				short_print(std::ostream &out = std::cout) const;
		void				full_print(std::ostream &out = std::cout) const;
		void				set_index(int index);
	private:
		Contact(const Contact& other);
		std::string out_preparation(const std::string& original) const;
	private:
		std::string			m_fname;
		std::string			m_lname;
		std::string			m_nname;
		std::string			m_pnumber;
		std::string			m_secret;
		int					m_index;
};

# endif
