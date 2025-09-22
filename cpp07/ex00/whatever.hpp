#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<class T>
void	swap(T& first, T& second) {
	T	temp = first;
	first = second;
	second = temp;
};

template<class T>
const T&	min(const T& first, const T& second) {
	return ((first < second) ? first : second);
};

template<class T>
const T&	max(const T& first, const T& second) {
	return ((first > second) ? first : second);
};

# endif
