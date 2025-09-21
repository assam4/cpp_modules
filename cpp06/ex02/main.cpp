# include <ctime>
# include <cstdlib>
# include <iostream>
# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

static Base*	generate(void) {
	int num = std::rand();
	if (!(num & 3)) num |= 1;
	switch(num & 3) {
		case 3:
			return new A();
		case 2:
			return new B();
		case 1:
			return new C();
	};
	return NULL;
}

void	identify(Base& p) {
	try {
		A a = dynamic_cast<A&>(p);
		std::cout << "Instance of A class" << std::endl;
		return ;
	}
	catch (...) {
	}
	try {
		B b = dynamic_cast<B&>(p);
		std::cout << "Instance of B class" << std::endl;
		return ;
	}
	catch (...) {
	}
	try {
		C c = dynamic_cast<C&>(p);
		std::cout << "Instance of C class" << std::endl;
		return ;
	}
	catch(...) {
	}
	std::cout << "Not Hierarchic object" << std::endl;
}
	
int	main() {
	  std::srand(static_cast<unsigned int>(std::time(0))); // инициализация генератора

    for (int i = 0; i < 10; ++i) {
        Base* obj = generate();
        identify(*obj);
        delete obj;
    }

    return 0;
}

