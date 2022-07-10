#include <Fixed.hpp>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

int main( void ) {
	std::cout << BLUE << "Constructors Tests" << RESET << std::endl << std::endl << GREEN;
	std::cout << "Default Constructor" << std::endl;
	Fixed a;
	std::cout << YELLOW << "a = " << a <<  GREEN << std::endl;
	std::cout << "Int Constructor" << std::endl;
	Fixed b( 10 );
	std::cout << YELLOW << "b = "  <<  b << GREEN << std::endl;
	std::cout << "Float Constructor" << std::endl;
	Fixed const c( 42.42f );
	std::cout << YELLOW << "c = " << c << GREEN << std::endl;
	std::cout << "Copy Constructor" << std::endl;
	Fixed const d( b );
	std::cout << YELLOW << "[copy of b] d = " << d << GREEN << std::endl;

	/* Operators */

	std::cout << RESET << std::endl;
	std::cout << BLUE << "Operators Tests" << RESET << std::endl << std::endl;

	std::cout << YELLOW << "[b + c]   " << RESET;
	std::cout << b + c << std::endl;
	std::cout << YELLOW << "[b - c]   " << RESET;
	std::cout << b - c << std::endl;
	std::cout << YELLOW << "[b * c]   " << RESET;
	std::cout << b * c << std::endl;
	std::cout << YELLOW << "[b / c]   " << RESET;
	std::cout << b / c << std::endl;
	std::cout << std::endl;

	/* Incremental & Decremental operators*/

	std::cout << BLUE << "Incremental & Decremental Operators Tests" << RESET << std::endl << std::endl;

	std::cout << YELLOW << "[a]   " << RESET;
	std::cout << a << std::endl;
	std::cout << YELLOW << "[++a] " << RESET;
	std::cout << ++a << std::endl;
	std::cout << YELLOW << "[a]   " << RESET;
	std::cout << a << std::endl;
	std::cout << YELLOW << "[a++] " << RESET;
	std::cout << a++ << std::endl;
	std::cout << YELLOW << "[a]   " << RESET;
	std::cout << a << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW << "[a]   " << RESET;
	std::cout << a << std::endl;
	std::cout << YELLOW << "[--a] " << RESET;
	std::cout << --a << std::endl;
	std::cout << YELLOW << "[a]   " << RESET;
	std::cout << a << std::endl;
	std::cout << YELLOW << "[a--] " << RESET;
	std::cout << a-- << std::endl;
	std::cout << YELLOW << "[a]   " << RESET;
	std::cout << a << std::endl;
	std::cout << std::endl;

	/* Comparations */
	std::cout << BLUE << "Comparations Tests" << RESET << std::endl << std::endl;

	std::cout << YELLOW << "[a > b]  " << RESET;
	std::cout << (a > b ? "True" : "False") << std::endl;
	std::cout << YELLOW << "[a < b]  " << RESET;
	std::cout << (a < b ? "True" : "False") << std::endl;
	std::cout << YELLOW << "[a >= b] " << RESET;
	std::cout << (a >= b ? "True" : "False") << std::endl;
	std::cout << YELLOW << "[a <= b] " << RESET;
	std::cout << (a <= b ? "True" : "False") << std::endl;
	std::cout << YELLOW << "[a == b] " << RESET;
	std::cout << (a == b ? "True" : "False") << std::endl;
	std::cout << YELLOW << "[a != b] " << RESET;
	std::cout << (a != b ? "True" : "False") << std::endl;
	std::cout << std::endl;


	std::cout << BLUE << "Member Functions Tests" << RESET << std::endl;

	std::cout << std::endl << GREEN << "getRawBits" << std::endl << RESET;
	std::cout << "a raw bits are " << a.getRawBits() << std::endl;
	std::cout << "b raw bits are " << b.getRawBits() << std::endl;
	std::cout << "c raw bits are " << c.getRawBits() << std::endl;
	std::cout << "d raw bits are " << d.getRawBits() << std::endl;

	std::cout << std::endl << GREEN << "setRawBits" << std::endl << RESET;
	a.setRawBits(256);
	std::cout << "a raw bits set to 256" << std::endl;
	b.setRawBits(512);
	std::cout << "b raw bits set to 512" << std::endl;

	std::cout << std::endl << GREEN << "toInt" << std::endl << RESET;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	std::cout << std::endl << GREEN << "toFloat" << std::endl << RESET;
	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	std::cout << "b is " << b.toFloat() << " as float" << std::endl;
	std::cout << "c is " << c.toFloat() << " as float" << std::endl;
	std::cout << "d is " << d.toFloat() << " as float" << std::endl;



	std::cout << std::endl << BLUE << "Non Member Functions Tests" << GREEN << std::endl;
	std::cout << std::endl << GREEN << "Max" << std::endl;
	std::cout << YELLOW << "[max(a, b)] " << RESET;
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << YELLOW << "[max(c, d)] " << RESET;
	std::cout << Fixed::max(c, d) << std::endl;
	std::cout << std::endl << GREEN << "Min" << std::endl;
	std::cout << YELLOW << "[min(a, b)] " << RESET;
	std::cout << Fixed::min(a, b) << std::endl;
	std::cout << YELLOW << "[min(c, d)] " << RESET;
	std::cout << Fixed::min(c, d) << std::endl;

	std::cout << std::endl;

	return (0);
}