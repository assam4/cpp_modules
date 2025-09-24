#include "Span.hpp"

Span::Span(): m_capacity(0) {
}

Span::Span(unsigned size): m_capacity(size) {
}

Span::~Span() {
}

Span::Span(const Span& oth)
	: m_numbers(oth.m_numbers), m_capacity(oth.m_capacity) {
}

Span&	Span::operator=(const Span& oth) {
	if (this != &oth) {
		m_numbers = oth.m_numbers;
		m_capacity = oth.m_capacity;
	}
	return *this;
}

void	Span::addNumber(int value) {
	if (m_numbers.size() == m_capacity)
		throw std::length_error("Span is full");
	m_numbers.insert(value);
}

int	Span::shortestSpan() const {
	if (m_numbers.empty() || m_numbers.size() == 1)
		throw std::out_of_range("Span is empty or contains 1 element");
	std::multiset<int>::iterator	first = m_numbers.begin();
	std::multiset<int>::iterator	second = first;
	++second;
	int	result = *second++ - *first++;
	for ( ; second != m_numbers.end(); ++second, ++first) {
		int current = *second - *first;
		if (current < result)
			result = current;
	}
	return result;
}

int	Span::longestSpan() const {
	if (m_numbers.empty() || m_numbers.size() == 1)
		throw std::out_of_range("Span is empty or contains 1 element");
	return (*(--m_numbers.end()) - *m_numbers.begin());
}
