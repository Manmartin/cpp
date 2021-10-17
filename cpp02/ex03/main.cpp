#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

void static	try_triagle(Point a, Point b, Point c, Point p) {
	int n;

	std::cout <<  "A = " << a <<  std::endl;
	std::cout <<  "B = " << b <<  std::endl;
	std::cout <<  "C = " << c <<  std::endl;
	std::cout <<  "P = " << p <<  std::endl;

	if ((n = bsp(a, b, c, p) + bsp(a, c, b, p) + bsp(b, a, c, p) + bsp(b, c, a, p) + bsp(c, a, b, p) + bsp(c, b, a, p)) == 6)
		std::cout << "P is in triangle" << std::endl;
	else if (n > 0)
		std::cout << "Program fail, sorry" << std::endl;
	else
		std::cout << "P is not in triangle" << std::endl;

}


int main( void ) {

	std::cout << "[Triangle 1]" << std::endl;
	try_triagle( Point(0, 0), Point(2, 3), Point(4, 0), Point(1, 1) );
	std::cout << std::endl;

	std::cout << "[Triangle 2]" << std::endl;
	try_triagle( Point(-2, -1), Point(1, 3), Point(4, -2), Point(-1, -0.5f) );
	std::cout << std::endl;

	std::cout << "[Triangle 3]" << std::endl;
	try_triagle( Point(-2, -1), Point(1, 3), Point(4, -2), Point(3.5f, -0.5f) );
	std::cout << std::endl;

	return 0;
}
