#include "Point.hpp"

/* Constructors and destructor */

Point::Point(void) : x(0), y(0) {
}

Point::~Point(void) {
}

Point::Point( Point const &point) : x(point.x), y(point.y) {
}

Point::Point( float const f1, float const f2) : x(f1), y(f2) {
}


Point const	&Point::operator=( Point const &point) {
	return point;
}


Fixed	Point::getX(void) const{
	return x;
}

Fixed	Point::getY(void) const{
	return y;
}

std::ostream &operator<<( std::ostream &o, Point const &point ) {
	o <<  '(' << point.getX() << ", " << point.getY() << ')';
	return o;
}
