#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int value) {
	for (typename T::iterator it = container.begin(); it != container.end(); ++it)
		if (*it == value)
			return it;
	throw std::runtime_error("Value not found");
}

template <typename T>
typename T::const_iterator	easyfind(const T& container, int value) {
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
		if (*it == value)
			return it;
	throw std::runtime_error("Value not found");
}

#endif
