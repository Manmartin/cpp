#include "Fixed.hpp"


int main( void ) {
	Fixed	a;
	Fixed	const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed	const c( Fixed( 25.5f ) / Fixed( 2 ) );
	Fixed  	d;

	std::cout << "[Comparison operators]" << std::endl;
	std::cout << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "b > c = " << (b > c ? "true" : "false") << std::endl;
	std::cout << "b < c = " << (b < c ? "true" : "false") << std::endl;
	std::cout << "b >= c = " << (b >= c ? "true" : "false") << std::endl;
	std::cout << "b <= c = " << (b <= c ? "true" : "false") << std::endl;
	d = b;
	std::cout << "d = " << d << std::endl;
	std::cout << "b >= d = " << (b >= d ? "true" : "false") << std::endl;
	std::cout << "b <= d = " << (b <= d ? "true" : "false") << std::endl;
	std::cout << "b == d = " << (b == d ? "true" : "false") << std::endl;
	std::cout << "b != d = " << (b != d ? "true" : "false") << std::endl;
	std::cout << std::endl;


	std::cout << "[Arithmetic operators]" << std::endl;
	std::cout << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "b + c = "  << b + c << std::endl;
	std::cout << "b - c = "  << b - c << std::endl;
	std::cout << "b * c = " << b * c << std::endl;
	std::cout << "b / c = " << b / c << std::endl;

	std::cout << std::endl;


	std::cout << "[Pre/post-incremental operator]" << std::endl;
	std::cout << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << std::endl;


	std::cout << "[Pre/post-decremental operator]" << std::endl;
	std::cout << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "--a = " << --a << std::endl;
	std::cout << "a--: " << a-- << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << std::endl;

	std::cout << "[Static functions]" << std::endl;
	std::cout << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "Fixed::min( b, c ) = " << Fixed::min( b, c ) << std::endl;
	std::cout << "Fixed::max( b, c ) = " << Fixed::max( b, c ) << std::endl;

	std::cout << std::endl;
	return 0;
}
