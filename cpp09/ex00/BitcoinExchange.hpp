#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <fstream>
# include <string>

class	BitcoinExchange{
	public:
		typedef std::map<std::string, float>::const_iterator const_iterator;
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange&);
		BitcoinExchange&	operator=(const BitcoinExchange&);
	public:
		void	loadDB(std::ifstream&);
		void	search(std::ifstream&) const;
	private:
		template <typename T>
		bool	rangeValidation(T value, T min, T max) const {
			return (min <= value && value <= max);
		}
		bool	basicValidation(const std::string&) const;
		bool	extendedValidation(const std::string&) const;
		bool	strictValidation(const std::string&, int) const;
		bool	validateDate(const std::string&) const;
		void	validateIntPart(const std::string&, bool) const;
		void	validateValue(const std::string&, bool) const;
		bool	validate(const std::string&, size_t) const;
		bool	validateDB(const std::string&, size_t) const;
		std::map<std::string, float>	m_data;
};

#endif
