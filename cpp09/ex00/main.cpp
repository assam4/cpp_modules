#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv) {
    try {
		if (argc != 2)
			throw std::invalid_argument("could not open file");
		BitcoinExchange	bt;
		std::ifstream db("data.csv");
		if (!db.is_open())
			throw std::runtime_error("could not open database");
		bt.loadDB(db);
        std::ifstream input(argv[1]);
        if (!input.is_open())
            throw std::runtime_error("could not open input file");
		bt.search(input);
        return 0;
    }
    catch(const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }
}
