#include "MutantStack.hpp"
#include <iostream>
#include <list>

void	testSubject(void)
{
	std::cout << "\n>>> RUNNING SUBJECT TESTS\n" << std::endl;
	/* Subject test */
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int>	s(mstack);
}

void	testReverseIteration(void)
{
	std::cout << "\n>>> RUNNING REVERSE ITERATOR TESTS\n" << std::endl;
	/* More tests */
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::reverse_iterator	rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator	rite = mstack.rend();
	++rit;
	--rit;
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}
	std::stack<int>	s(mstack);
}

void	runListIteration(void)
{
	std::cout << "\n>>> LIST ITERATION\n" << std::endl;
	/* List test for comparison */
	std::list<int>	list;

	list.push_back(5);
	list.push_back(17);

	std::cout << list.back() << std::endl;
	list.pop_back();
	std::cout << list.size() << std::endl;

	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);

	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator ite = list.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int>	l(list);
}

void	runListReverseIteration(void)
{
	std::cout << "\n>>> LIST REVERSE ITERATION\n" << std::endl;
	/* List test for comparison */
	std::list<int>	list;

	list.push_back(5);
	list.push_back(17);

	std::cout << list.back() << std::endl;
	list.pop_back();
	std::cout << list.size() << std::endl;

	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);

	std::list<int>::reverse_iterator it = list.rbegin();
	std::list<int>::reverse_iterator ite = list.rend();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int>	l(list);
}

int	main(void)
{
	testSubject();
	runListIteration();
	testReverseIteration();
	runListReverseIteration();

	std::cout << "All tests completed. The two outputs should be identical." << std::endl;
	return (0);
}
