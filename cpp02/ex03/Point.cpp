#include <Point.hpp>

/* Constructors & Destructor */

Point::Point( void ) : _x(0), _y(0) {
}

Point::Point( Point const &ref ) : _x(ref._x), _y(ref._y) {
}

Point::Point( float const x, float const y ) : _x(x), _y(y) {
}

Point::~Point( void ) {
}

/* Operators */

Point const	&Point::operator=( Point const &ref ) {
	return ref;
}

Point	Point::operator+( Point const &ref ) const {
	float const x = this->_x.toFloat() + ref._x.toFloat();
	float const y = this->_y.toFloat() + ref._y.toFloat(); 
	return Point(x, y);
}

Point	Point::operator-( Point const &ref ) const {
	float const x = this->_x.toFloat() - ref._x.toFloat();
	float const y = this->_y.toFloat() - ref._y.toFloat(); 
	return Point(x, y);
}

Point	Point::operator*( Point const &ref ) const {
	float const x = this->_x.toFloat() * ref._x.toFloat();
	float const y = this->_y.toFloat() * ref._y.toFloat(); 
	return Point(x, y);
}

Point	Point::operator/( Point const &ref ) const {
	float const x = this->_x.toFloat() / ref._x.toFloat();
	float const y = this->_y.toFloat() / ref._y.toFloat(); 
	return Point(x, y);
}


Fixed const	&Point::getX( void ) const {
	return this->_x;
}

Fixed const	&Point::getY( void ) const {
	return this->_y;
}

std::ostream &operator<<( std::ostream &o, Point const &point ) {
	o <<  '(' << point.getX() << ", " << point.getY() << ')';
	return o;
}
