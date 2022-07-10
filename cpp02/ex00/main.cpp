#include <Fixed.hpp>

int main(void) {
	Fixed a;
	Fixed b( a );
	Fixed c;

	b.setRawBits(5);
	c = b;
	b.setRawBits(10);

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}