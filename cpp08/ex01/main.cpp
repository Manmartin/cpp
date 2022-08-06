#include <span.hpp>
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

int main(void) {
	std::cout << BLUE << "Basic test: Span(5)\n" << RESET;
	Span sp = Span(7);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << YELLOW << "* numbers {5, 3, 17, 9, 11} *\n\n" << RESET;
	std::cout << "Shortest span = " << sp.shortestSpan() << '\n';
	std::cout << "Longest span = " << sp.longestSpan() << '\n';
	std::cout << '\n';

	std::cout << BLUE << "Deep copy test\n" << RESET;
	std::cout << YELLOW << "* numbers {5, 3, 17, 9, 11, 2, 33} *\n\n" << RESET;
	{
		Span copy = sp;
		copy.addNumber(2);
		copy.addNumber(33);
		std::cout << "Copy shortest span = " << copy.shortestSpan() << '\n';
		std::cout << "Copy longest span = " << copy.longestSpan() << '\n';
	}
	std::cout << "Original shortest span = " << sp.shortestSpan() << '\n';
	std::cout << "Original longest span = " << sp.longestSpan() << '\n';
	std::cout << '\n';

	std::cout << BLUE << "Big test with iterator: Span(100000)\n\n" << RESET;
	{
		std::vector<int> v;
		Span a(100000);
		for (unsigned i = 1; i <= 100000; i++)
			v.push_back(i * 2);
		a.betterAddNumber(v.begin(), v.end());
		std::cout << "Shortest span = " << a.shortestSpan() << '\n';
		std::cout << "Longest span = " << a.longestSpan() << '\n';
	}
	std::cout << '\n';
	{
		std::cout << BLUE << "Big test with a rangue of numbers: Span(100000)\n\n" << RESET;
		Span a(100000);
		a.betterAddNumber(UINT_MAX, 100000, 1);
		std::cout << "Shortest span = " << a.shortestSpan() << '\n';
		std::cout << "Longest span = " << a.longestSpan() << '\n';
	}
	std::cout << '\n';

	std::cout << BLUE << "Error tests\n\n" << RESET;
	std::cout << YELLOW << "* Span(0).addNumber(42) *\n" << RESET;
	try {
		Span fail;
		fail.addNumber(42);
	} catch (std::exception &e) {
		std::cout << RED << e.what() << '\n' << RESET; 
	}
	std::cout << '\n';
	std::cout << YELLOW << "* Span(1).addNumber(21).addNumber(42) *\n" << RESET;
	try {
		Span fail(1);
		fail.addNumber(21);
		fail.addNumber(42);
	} catch (std::exception &e) {
		std::cout << RED << e.what() << '\n' << RESET; 
	}
	std::cout << '\n';
	std::cout << YELLOW << "* Span(0).shortestSpan() *\n" << RESET;
	try {
		Span noSpan;
		noSpan.shortestSpan();
	} catch (std::exception &e) {
		std::cout << RED << e.what() << '\n' << RESET; 
	}
	std::cout << '\n';
	std::cout << YELLOW << "* Span(0).longestSpan() *\n" << RESET;
	try {
		Span noSpan;
		noSpan.longestSpan();
	} catch (std::exception &e) {
		std::cout << RED << e.what() << '\n' << RESET; 
	}
	std::cout << '\n';
	std::cout << YELLOW << "* Span(2).addNumber(42).shortestSpan() *\n" << RESET;
	try {
		Span noSpan(2);
		noSpan.addNumber(42);
		noSpan.shortestSpan();
	} catch (std::exception &e) {
		std::cout << RED << e.what() << '\n' << RESET; 
	}
	std::cout << '\n';
	std::cout << YELLOW << "* Span(2).addNumber(42).longestSpan() *\n" << RESET;
	try {
		Span noSpan(2);
		noSpan.addNumber(42);
		noSpan.longestSpan();
	} catch (std::exception &e) {
		std::cout << RED << e.what() << '\n' << RESET; 
	}
}
