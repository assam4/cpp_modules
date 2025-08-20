#ifndef STREAMEDITOR_HPP
# define STREAMEDITOR_HPP

# include <fstream>
# include "StringReplace.hpp"

class StreamEditor {
	public:
		StreamEditor();
		~StreamEditor();
	public:
		bool	set_istream(const char*);
		bool	set_ostream(const char*);
		bool	set_filter(const std::string&, const std::string&);
		bool	readline();
		bool	writeline();
	private:
		StreamEditor(const StreamEditor&);
		StreamEditor& operator=(const StreamEditor&);
	private:
		std::ifstream	m_i;
		std::ofstream	m_o;
		StringReplace	m_filter;
		std::string		m_buffer;
};

#endif	
