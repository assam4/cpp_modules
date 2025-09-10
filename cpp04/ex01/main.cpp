#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
	return 0;
}

/*

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const int SIZE = 4;
    Animal* animals[SIZE];

    // Создаём половину Dogs и половину Cats
    for (int i = 0; i < SIZE; ++i) {
        if (i < SIZE / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    // Проверяем makeSound и тип
    for (int i = 0; i < SIZE; ++i) {
        std::cout << "Animal[" << i << "] type: " << animals[i]->getType() << std::endl;
        animals[i]->makeSound();
    }

    // Копируем Dog и Cat для проверки deep copy
    Dog* dog1 = new Dog();
    Dog* dog2 = new Dog(*dog1); // копия
    Cat* cat1 = new Cat();
    Cat* cat2 = new Cat(*cat1); // копия

    std::cout << "\nTesting deep copy:\n";
    dog1->makeSound();
    dog2->makeSound();
    cat1->makeSound();
    cat2->makeSound();

    // Удаляем все объекты
    for (int i = 0; i < SIZE; ++i)
        delete animals[i];

    delete dog1;
    delete dog2;
    delete cat1;
    delete cat2;

    return 0;
}
*/
