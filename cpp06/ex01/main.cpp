#include <Data.hpp>
#include <stdint.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

uintptr_t serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}

int main(void) {
	
	std::cout << BLUE << "Creating Data and using printData\n" << RESET;
	Data *test1 = new Data(4, 4.2, 5.26);
	Data *test2 = new Data;
	uintptr_t serialize1;
	uintptr_t serialize2;

	test1->printData();
	std::cout << '\n';
	test2->printData();
	std::cout << '\n';
	
	std::cout << BLUE << "Serialize data\n" << RESET;
	serialize1 = serialize(test1);
	serialize2 = serialize(test2);
	std::cout << serialize1 << '\n';
	std::cout << serialize2 << '\n';
	std::cout << '\n';

	std::cout << BLUE << "Deserialize Data and using printData\n" << RESET;
	test1 = deserialize(serialize1);
	test2 = deserialize(serialize2);
	test1->printData();
	std::cout << '\n';
	test2->printData();
	std::cout << '\n';

	
	delete test1;
	delete test2;
	return 0;
}
