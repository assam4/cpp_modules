#include "StringReplace.hpp"

std::string	StringReplace::operator()(const std::string& source) const {
	std::string	filtered;
	size_t		prev_pos = 0;
	size_t		current_pos = 0;

	if (!source.empty()) {
		do {
			current_pos = source.find(this->m_search, prev_pos);
			if (current_pos == std::string::npos)
				break ;
			if (current_pos != prev_pos)
				filtered.append(source.substr(prev_pos, current_pos - prev_pos));
			filtered.append(this->m_replace);
			prev_pos = current_pos + this->m_search.length();
		} while (true);
		filtered.append(source.substr(prev_pos));
	}
	return filtered;
}

void	StringReplace::set(const std::string& s1, const std::string& s2) {
	if (s1.empty() || s2.empty())
		return ;
	this->m_search = s1;
	this->m_replace = s2;
}

bool	StringReplace::empty() const {
	return (this->m_search.empty() || this->m_replace.empty());
}
