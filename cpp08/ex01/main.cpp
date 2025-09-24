#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

int	main(void)
{
	try {

		{
		Span	sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		}
		{
		const size_t numNumbers = 10000;
		Span sp(numNumbers);

		std::vector<int> numbers(numNumbers);
		std::srand(std::time(0));
		for (size_t i = 0; i < numNumbers; ++i)
		{
			numbers[i] = std::rand() % 1000 + 1;
		}

		std::cout << "Adding " << numNumbers << " numbers..." << std::endl;
		sp.addNumber(numbers.begin(), numbers.end());

		std::cout << "Calculating spans..." << std::endl;
		int shortest = sp.shortestSpan();
		int longest = sp.longestSpan();

		std::cout << "Shortest span: " << shortest << std::endl;
		std::cout << "Longest span: " << longest << std::endl;
		}
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	catch (...) {
		std::cout << "Undefined error!" << std::endl;
	}
	return (0);
}
