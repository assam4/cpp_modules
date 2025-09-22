#include <iostream>
#include <string>
#include "Iter.hpp"

// Функция печати (работает с const T&)
template <typename T>
void print(const T& x) {
    std::cout << x << " ";
}

// Функция, которая увеличивает число (работает с T&)
void increment(int& x) {
    x++;
}

int main() {
    // Тест с int
    int arrInt[] = {1, 2, 3, 4, 5};
    size_t lenInt = sizeof(arrInt) / sizeof(arrInt[0]);

    std::cout << "Original int array: ";
    iter(arrInt, lenInt, print<int>);
    std::cout << std::endl;

    iter(arrInt, lenInt, increment);
    std::cout << "After increment:   ";
    iter(arrInt, lenInt, print<int>);
    std::cout << std::endl << std::endl;

    // Тест с double
    double arrDouble[] = {1.1, 2.2, 3.3};
    size_t lenDouble = sizeof(arrDouble) / sizeof(arrDouble[0]);

    std::cout << "Double array: ";
    iter(arrDouble, lenDouble, print<double>);
    std::cout << std::endl << std::endl;

    // Тест с std::string
    std::string arrStr[] = {"apple", "banana", "cherry"};
    size_t lenStr = sizeof(arrStr) / sizeof(arrStr[0]);

    std::cout << "String array: ";
    iter(arrStr, lenStr, print<std::string>);
    std::cout << std::endl;

    return 0;
}

