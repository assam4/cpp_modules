#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include	<limits>
# include	<stdexcept>
# include	"Contact.hpp"

extern const std::string	Prompt;
extern const std::string    Gmenu;
extern const std::string    Add;
extern const std::string    Search;
extern const std::string    Exit;
extern const std::string    Select;
extern const std::string    AddInfo;
extern const std::string    SearchInfo;
extern const std::string    ExitInfo;
extern const std::string    Smode;
extern const std::string    Sselect;
extern const std::string    NonNumeric;
extern const std::string    Index_error;
extern const std::string    Amode;
extern const std::string    WrongInput;
extern const std::string    AttemptsEnd;
extern const std::string    FirstName;
extern const std::string    LastName;
extern const std::string    NickName;
extern const std::string    PhoneNumber;
extern const std::string    Secret;
extern const std::string	StreamError;
extern const std::string	SucAdded;
static const int			Contacts_count = 8;

class Phonebook {
	public:
		Phonebook();
	public:
		bool	add(const std::string& fname, const std::string& lname, const std::string &nname,
					const std::string& pnum, const std::string& secret);
		bool	list_print(std::ostream& out = std::cout) const;
		bool	single_print(int index, std::ostream& out = std::cout) const;
	private:
		Phonebook(const Phonebook& other);
		Phonebook& operator= (const Phonebook& other);
	private:
		int		m_size;
		Contact m_contacts[Contacts_count];
};

#endif
