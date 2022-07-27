#include <Array.hpp>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

typedef struct {
	double i;
	double x;
} nc;

#define MAX_VAL 750

int main(void) {
 	{
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}
		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;//
 	}

	{
		unsigned int size;
		std::cout << BLUE << "Int\n\n";
		std::cout << GREEN << "Creating 2 Array<int> (Empty & size = 5)\n\n" << RESET;
		Array<int> arrInt; 
		Array<int> arrInt2(5);
		std::cout << "size = " << arrInt.size() << '\n';
		std::cout << "size = " << arrInt2.size() << '\n';
		std::cout << '\n';

		std::cout << GREEN << "Using [] operator to change and print array elements\n\n" << RESET;
		arrInt = arrInt2;
		arrInt2 = arrInt;
		size = arrInt2.size();
		for (unsigned int i = 0; i < size; i++) {
			arrInt2[i] = i;
			std::cout << arrInt2[i] << '\n';
		}
		std::cout << '\n';
		size = arrInt.size();
		for (unsigned int i = 0; i < size; i++) {
			std::cout << arrInt[i] << '\n';
		}
		std::cout << '\n';

		std::cout << GREEN << "Using [] operator in a const Array<int>\n\n" << RESET;
		Array<int> const constArr(5);
		size = constArr.size();
		for (unsigned int i = 0; i < size; i++) {
			std::cout << constArr[i] << '\n';
		}

		std::cout << '\n';
		std::cout << GREEN << "trying bad index in Array<int>\n\n" << RESET;
		try {
			size = arrInt.size();
			arrInt[size];
		} catch (std::exception &e) {
			std::cout << RED << "Bad index\n" << RESET;
		}
	}
	{
		unsigned int size;
		std::cout << BLUE << "String\n\n";
		std::cout << GREEN << "Creating 2 Array<std::string> (Empty & size = 5)\n\n" << RESET;
		Array<std::string> arrStr; 
		Array<std::string> arrStr2(5);
		std::cout << "size = " << arrStr.size() << '\n';
		std::cout << "size = " << arrStr2.size() << '\n';
		std::cout << '\n';

		std::cout << GREEN << "Using [] operator to change and print array elements\n\n" << RESET;
		arrStr = arrStr2;
		arrStr2 = arrStr;
		size = arrStr2.size();
		for (unsigned int i = 0; i < size; i++) {
			arrStr2[i] = "example";
			std::cout << "'" << arrStr2[i] << "'" << '\n';
		}
		std::cout << '\n';
		size = arrStr.size();
		for (unsigned int i = 0; i < size; i++) {
			std::cout << "'" << arrStr[i] << "'" << '\n';
		}
		std::cout << '\n';

		std::cout << GREEN << "Using [] operator in a const Array<std::string>\n\n" << RESET;
		Array<std::string> const constArr(5);
		size = constArr.size();
		for (unsigned int i = 0; i < size; i++) {
			std::cout << "'" << constArr[i]  << "'" << '\n';
		}

		std::cout << '\n';
		std::cout << GREEN << "trying bad index in Array<std::string>\n\n" << RESET;
		try {
			size = arrStr.size();
			arrStr[size];
		} catch (std::exception &e) {
			std::cout << RED << "Bad index\n" << RESET;
		}
	}
	{
		unsigned int size;
		std::cout << BLUE << "nc (complex data type)\n\n";
		std::cout << GREEN << "Creating 2 Array<nc> (Empty & size = 5)\n\n" << RESET;
		Array<nc> arrNc; 
		Array<nc> arrNc2(5);
		std::cout << "size = " << arrNc.size() << '\n';
		std::cout << "size = " << arrNc2.size() << '\n';
		std::cout << '\n';

		std::cout << GREEN << "Using [] operator to change and print array elements\n\n" << RESET;
		arrNc = arrNc2;
		arrNc2 = arrNc;
		size = arrNc2.size();
		for (unsigned int i = 0; i < size; i++) {
			arrNc2[i].x = i;
			arrNc2[i].i = size - i;
			std::cout << arrNc2[i].x << " " << arrNc2[i].i << '\n';
		}
		std::cout << '\n';
		size = arrNc.size();
		for (unsigned int i = 0; i < size; i++) {
			std::cout << arrNc[i].x << " " << arrNc[i].i << '\n';
		}
		std::cout << '\n';

		std::cout << GREEN << "Using [] operator in a const Array<nc>\n\n" << RESET;
		Array<nc> const constArr(5);
		size = constArr.size();
		for (unsigned int i = 0; i < size; i++) {
			std::cout << constArr[i].x << " " << constArr[i].i << '\n';
		}

		std::cout << '\n';
		std::cout << GREEN << "trying bad index in Array<nc>\n\n" << RESET;
		try {
			size = arrNc.size();
			arrNc[size];
		} catch (std::exception &e) {
			std::cout << RED << "Bad index\n" << RESET;
		}
	}
	return 0;
}
