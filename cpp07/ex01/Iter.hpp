#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

template <class T, size_t n>
void	iter(T (&arr)[n], void (*func)(T&)) {
   for (size_t i = 0; i < n; ++i)
		func(arr[i]);
}

template <class T, size_t n>
void	iter(T (&arr)[n], void (*func)(const T&)) {
	for (size_t i = 0; i < n; ++i)
		func(arr[i]);
};

template <class T>
void	iter(T *arr, size_t n , void (*f)(T&)) {
	for (size_t i = 0; i < n; ++i)
		f(arr[i]);
};

template <class T>
void	iter(T *arr, size_t n, void (*f)(const T&)) {
   for (size_t i = 0; i < n; ++i)
		f(arr[i]);
};

#endif
