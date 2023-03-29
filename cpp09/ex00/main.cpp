#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "Wrong parameters number\n";
		return 1;
	}
	BitcoinExchange btc;
	if (!btc.loadFile(argv[1]))
		return 1;
	btc.printValues();
	return 0;
}
