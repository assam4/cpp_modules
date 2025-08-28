#include "StreamEditor.hpp"

StreamEditor::StreamEditor() {
}

StreamEditor::~StreamEditor() {
	if (this->m_i.is_open())
		this->m_i.close();
	if (this->m_o.is_open())
		this->m_o.close();
}

bool	StreamEditor::set_istream(const char *filename) {
	if (this->m_i.is_open())
		this->m_i.close();
	this->m_buffer.clear();
	this->m_i.open(filename);
	return this->m_i.is_open();
}

bool	StreamEditor::set_ostream(const char *filename) {
	if (this->m_o.is_open())
		this->m_o.close();
	this->m_o.open(filename);
	return this->m_o.is_open();
}

bool	StreamEditor::set_filter(const std::string& s1, const std::string& s2) {
	this->m_filter.set(s1, s2);
	return !this->m_filter.empty();
}

bool	StreamEditor::readline() {
	std::string	buffer(4096, '\0');

	if (!this->m_i.is_open())
		return  false;
	m_i.read(&buffer[0], buffer.size());
	ssize_t	count = m_i.gcount();
	if (!m_i.good() && !count) {
		this->m_i.close();
		return false;
	}
	buffer.resize(count);
	if (!this->m_filter.empty())
		this->m_buffer = m_filter(buffer);
	else
		this->m_buffer = buffer;
	return true;
}

bool	StreamEditor::writeline() {
	if (!this->m_o.is_open())
		return false;
	this->m_o << this->m_buffer;
	return this->m_o.good();
}
