#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    try {
        std::cout << "=== Test with std::vector<int> ===" << std::endl;
        std::vector<int> vec;
        for (int i = 0; i < 5; ++i)
            vec.push_back(i * 10); // 0, 10, 20, 30, 40

        std::vector<int>::iterator it1 = easyfind(vec, 20);
        std::cout << "Found in vector: " << *it1 << std::endl;

        // проверим, что можем изменить найденный элемент
        *it1 = 99;
        std::cout << "Modified element: " << vec[2] << std::endl;

        std::cout << "\n=== Test with const std::list<int> ===" << std::endl;
        const std::list<int> lst = {5, 15, 25, 35};

        std::list<int>::const_iterator it2 = easyfind(lst, 25);
        std::cout << "Found in const list: " << *it2 << std::endl;

        std::cout << "\n=== Test exception ===" << std::endl;
        easyfind(vec, 123); // этого элемента нет
    }
    catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
}
