# include "BitcoinExchange.hpp"
# include <iostream>
# include <exception>
# include <cstdlib>

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& oth): m_data(oth.m_data) {
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& oth) {
	if (this != &oth)
		m_data = oth.m_data;
	return *this;
}

bool	BitcoinExchange::basicValidation(const std::string& data) const {
	size_t	len = data.length();
	if (!rangeValidation<size_t>(len, 1, 11))
		return false;
	for (size_t	i = 0; i < len; ++i)
		if (!std::isdigit(data[i]))
			return false;
	return true;
}

bool	BitcoinExchange::extendedValidation(const std::string& data) const {
	if (!basicValidation(data))
		return false;
	int num = std::atoi(data.c_str());
	return (rangeValidation(num, 1, 12));
}

bool	BitcoinExchange::strictValidation(const std::string& data, int month) const {
	if (!basicValidation(data))
			return false;
	int	day = std::atoi(data.c_str());
	if (!rangeValidation(day, 1, 31) || (month == 2 && !rangeValidation(day, 1, 29)))
		return false;
	else if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
		return false;
	return true;
}

bool	BitcoinExchange::validateDate(const std::string& date) const {
	size_t	sep1 = date.find('-');
	if (sep1 == std::string::npos || !basicValidation(date.substr(0, sep1)))
		return false;
	size_t	sep2 = date.find('-', sep1 + 1);
	if (sep2 == std::string::npos)
	   return false;
	std::string str = date.substr(sep1 + 1, sep2 - sep1 - 1);
	if (!extendedValidation(str))
	   return false;
	if (!strictValidation(date.substr(sep2 + 1), std::atoi(str.c_str())))
		return false;
	return true;
}

void	BitcoinExchange::validateIntPart(const std::string& val, bool isDB) const {
	size_t	len = val.length();
	for (size_t i = 0; i < len; ++i)
		if (!i && val[i] == '-')
			throw std::invalid_argument("not a positive number.");
		else if (!std::isdigit(val[i]))
			throw std::invalid_argument("Invalid format.");
		else if (!isDB && (i > 4 || (len == 4 && ((!i && val[i] != '1') || (i && val[i] != '0')))))
			throw std::invalid_argument("too large a number.");
}

void	BitcoinExchange::validateValue(const std::string& value, bool isDB) const {
	size_t	sep = value.find('.');
	if (sep == std::string::npos)
		validateIntPart(value, isDB);
	else { 
		validateIntPart(value.substr(0, sep), isDB);
		if (!basicValidation(value.substr(sep + 1)))
				throw std::invalid_argument("Invalid format.");
	}
}

bool	BitcoinExchange::validate(const std::string& src, size_t sep) const {
	try {
		if ((sep == std::string::npos) ||  !rangeValidation<size_t>(sep, 1, src.length() - 1)
			|| src[sep - 1] != ' ' || src[sep + 1] != ' ' || !validateDate(src.substr(0, sep - 1)))
			throw std::invalid_argument("bad input => " + src.substr(0, sep - 1));
		validateValue(src.substr(sep + 2), false);
		return true;
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
		return false;
	}
	catch (...) {
		std::cout << "Unknown error!." << std::endl;
		return false;
	}
}

bool	BitcoinExchange::validateDB(const std::string& src, size_t sep) const {
   try {
	   if ((sep == std::string::npos) || !rangeValidation<size_t>(sep, 1, src.length() - 1))
		   throw std::invalid_argument("Invalid Data Base!.");
	   if (!validateDate(src.substr(0, sep)))
			throw std::invalid_argument("Invalid Data Base");
	   validateValue(src.substr(sep + 1), true);
		return true;
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
		return false;
	}
	catch (...) {
		std::cout << "Unknown error!." << std::endl;
		return false;
	}
}

void	BitcoinExchange::loadDB(std::ifstream& stream) {
	std::string	line;
	while (std::getline(stream, line)) {
		size_t	sep = line.find(',');
		if (validateDB(line, sep))
			m_data[line.substr(0, sep)] = std::atof(line.substr(sep + 1).c_str());
	}
}

void	BitcoinExchange::search(std::ifstream& stream) const {
	std::string	line;
	while (std::getline(stream, line)) {
		if (line.empty())
			continue ;
		size_t	sep = line.find('|');
		if (validate(line, sep)) {
			float   count = std::atof(line.substr(sep + 1).c_str());
			std::string date = line.substr(0, sep);
			std::cout << date << " => " << count << " = ";
			if (m_data.empty())
				std::cout << count << std::endl;
			else {
				const_iterator iter = m_data.lower_bound(date);
				if (iter == m_data.end() || (iter != m_data.begin() && iter->first > date))
					--iter;
				std::cout << count * iter->second << std::endl;
			}
		}
	}
}
