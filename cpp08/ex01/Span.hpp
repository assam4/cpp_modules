#ifndef SPAN_HPP
# define SPAN_HPP

# include <set>
# include <stdexcept>

class	Span{
	public:
		~Span();
		Span(unsigned);
		Span(const Span&);
		Span&	operator=(const Span&);
	public:
		void	addNumber(int);
		template <typename T>
		void	addNumber(T begin, const T& end) {
			for (; begin != end; ++begin) {
				if (m_numbers.size() == m_capacity)
					throw std::out_of_range("Span is full");
				m_numbers.insert(*begin);
			}
		}
		int		shortestSpan() const;
		int		longestSpan() const;
	private:
		std::multiset<int>	m_numbers;
		unsigned			m_capacity;
		Span();
};

#endif
