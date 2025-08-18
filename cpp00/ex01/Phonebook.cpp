#include "Phonebook.hpp"

Phonebook::Phonebook() {
	this->m_size = Start_index;
}

bool	Phonebook::add(const std::string& fname, const std::string& lname, const std::string& nname,
						const std::string& pnum , const std::string& secret) {
	
	++this->m_size;
	Contact temp(fname, lname, nname, pnum, secret);
	if (this->m_size > Contacts_count) {
		for (int i = Contacts_count - 1; i; --i) {
			this->m_contacts[i] = this->m_contacts[i - 1];
		}
		--this->m_size;
	}
	this->m_contacts[Contacts_count - this->m_size] = temp;
	this->m_contacts[Contacts_count - this->m_size].set_index(this->m_size);
	return true;
}

bool	Phonebook::list_print(std::ostream& out) const {
	if (!this->m_size)
		return false;
	for (int i = Contacts_count - 1; i >= Contacts_count - this->m_size; --i)
		this->m_contacts[i].short_print(out);
	return true;
}

bool	Phonebook::single_print(int index, std::ostream& out) const {
	if (index <= 0 || index > this->m_size) {
		out << Index_error << std::endl;
		return false;
	}
	else {
		this->m_contacts[Contacts_count - index].full_print(out);
		return true;
	}
}
