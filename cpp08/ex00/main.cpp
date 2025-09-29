#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    try {
        std::cout << "=== Test with std::vector<int> ===" << std::endl;
        std::vector<int> vec;
        for (int i = 0; i < 5; ++i)
            vec.push_back(i * 10);
        std::vector<int>::iterator it1 = easyfind(vec, 20);
        std::cout << "Found in vector: " << *it1 << std::endl;
        *it1 = 99;
        std::cout << "Modified element: " << vec[2] << std::endl;
        std::cout << "\n=== Test with const std::list<int> ===" << std::endl;
        std::list<int> lst;
	    lst.push_back(5);
		lst.push_back(15);
		lst.push_back(25);
		lst.push_back(35);
        std::list<int>::const_iterator it2 = easyfind(lst, 25);
        std::cout << "Found in const list: " << *it2 << std::endl;
        std::cout << "\n=== Test exception ===" << std::endl;
        easyfind(vec, 123);
    }
    catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
}
