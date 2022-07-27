#include <iter.hpp>
#include <iostream>

static void printInt( int const &x ) {
	std::cout << "int: " << x << '\n';
}
static void printFloat( float const &x ) {
	std::cout << "float: " << x << '\n';
}
static void printDouble( double const &x ) {
	std::cout << "double: " << x << '\n';
}
static void printString( std::string const &x ) {
	std::cout << "string: " << x << '\n';
}

int main() {
	int arrInt[] = { 0, 1, 2, 3, 4 };
	float arrFloat[] = { 0.5, 1.5, 2.5, 3.5, 4.5 };
	double arrDouble[] = { 0.55, 1.55, 2.55, 3.55, 4.55 };
	std::string arrStr[] = {"a", "b", "c", "d", "e"};
	std::cout << "With Int\n\n";
	iter( arrInt, 5, printInt );
	std::cout << '\n';
	
	std::cout << "With Float\n\n";
	iter( arrFloat, 5, printFloat );
	std::cout << '\n';
	
	std::cout << "With Double\n\n";
	iter( arrDouble, 5, printDouble );
	std::cout << '\n';

	std::cout << "With string\n\n";
	iter( arrStr, 5, printString );
	std::cout << '\n';
	return 0;
}
