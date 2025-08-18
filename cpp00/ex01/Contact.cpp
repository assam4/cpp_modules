#include "Contact.hpp"

Contact::Contact (const std::string& fname, const std::string& lname,
		const std::string& nname, const std::string& pnum,
		const std::string& secret, int index) {
	this->m_fname = fname;
	this->m_lname = lname;
	this->m_nname = nname;
	this->m_pnumber = pnum;
	this->m_secret = secret;
	this->m_index = index;

}

Contact& Contact::operator= (const Contact& other) {
	if (this != &other) {
		this->m_fname = other.m_fname;
		this->m_lname = other.m_lname;
		this->m_nname = other.m_nname;
		this->m_pnumber = other.m_pnumber;
		this->m_secret = other.m_secret;
	}
	return *this;
}

const std::string&  Contact::get_fname() const {
	return this->m_fname;
}

const std::string&  Contact::get_lname() const {
	return this->m_lname;
}

const std::string&  Contact::get_nname() const {
	return this->m_nname;
}

const std::string& Contact::get_pnum() const {
	return this->m_pnumber;
}

const std::string& Contact::get_secret() const {
	return this->m_secret;
}

int	Contact::get_index() const {
	return this->m_index;
}

void	Contact::set_index(int index) {
	this->m_index = index;
}

std::string Contact::out_preparation(const std::string& original) const {

	if (original.length() <=  Required_length)
		return original;
	std::string helper = original.substr(0, 10);
	helper[Required_length - 1] = '.';
	return helper;
}

void	Contact::short_print(std::ostream& out) const {
	out << std::right << std::setfill(' ');
	out <<  '|' << std::setw(Required_length) << this->m_index  << '|'
		<< std::setw(Required_length) << out_preparation(this->m_fname) << '|'
		<< std::setw(Required_length) << out_preparation(this->m_lname) << '|'
		<< std::setw(Required_length) << out_preparation(this->m_nname) << '|'
		<< std::endl;
	out.flags(std::ios::fmtflags(0));
};

void	Contact::full_print(std::ostream& out) const {
	out << "Index: " << this->m_index << '\n'
		<< "First name: " << this->m_fname << '\n' 
		<< "Last name: " << this->m_lname << '\n'
		<< "Nickname: " << this->m_nname << '\n'
		<< "Phone number: " << this->m_pnumber << '\n'
		<< "Secret: " << this->m_secret << std::endl;
}
