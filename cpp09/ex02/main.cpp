#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <list>
# include "PmergeMe.hpp"

bool	argsValidation(char ** argv) {
	for (size_t i = 0; argv[i]; ++i) {
		for (size_t x = 0; argv[i][x]; ++x)
			if (!std::isdigit(argv[i][x]))
				return false;
		if (!std::atoi(argv[i]))
			return false;
	}
	return true;
}

std::vector<int>	getNums(char **argv) {
	std::vector<int> nums;
	for (size_t i = 0; argv[i]; ++i)
		nums.push_back(std::atoi(argv[i]));
	return nums;
}

template <typename T>
void	Containerprint(const T& contianer) {
	typedef typename T::const_iterator const_iterator;
	for (const_iterator it = contianer.begin(); it != contianer.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;
}

template <typename T>
clock_t	getSortingTime(T& container) {
	PmergeMe sorter;
	clock_t start = clock();
	sorter(container);
	return clock() - start;
}

void	print_result(std::vector<int>& v, clock_t t1, clock_t t2) {
	std::cout << "Before: ";
	Containerprint(v);
	std::cout << "After: ";
	std::sort(v.begin(), v.end());
	Containerprint(v);
	std::cout << "Time to process a range of " << v.size()
		<< " elements with std::vector: " << static_cast<double>(t1) / CLOCKS_PER_SEC * 1000.0 << " us\n";
	std::cout << "Time to process a range of " << v.size()
		<< " elements with std::list: " << static_cast<double>(t2) / CLOCKS_PER_SEC * 1000.0 << " us\n";
}

void	test(std::vector<int> v) {
	std::list<int> l(v.begin(), v.end());
	clock_t time_1 = getSortingTime(v);
	clock_t time_2 = getSortingTime(l);
	print_result(v, time_1, time_2);
}

int main(int argc, char **argv) {
	try {
		if (argc == 1)
			throw std::runtime_error("Arguments doesn't set!.");
		if (!argsValidation(argv + 1))
			throw std::runtime_error("Invalid Arguments!.");
		test(getNums(argv + 1));
		return 0;
	}
	catch(const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
		return 1;
	}
	catch (...) {
		std::cout << "Error: Undefined!" << std::endl;
		return 1;
	}
}
