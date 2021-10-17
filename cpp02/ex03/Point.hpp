#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:

		Fixed const x;
		Fixed const y;

	public:

		Point( void );
		Point( Point const &point );
		Point( float const f1, float const f2 );
		~Point( void );

		Point const &operator=( Point const &point );

		Fixed	getX( void ) const;
		Fixed	getY( void ) const;
};

std::ostream &operator<<( std::ostream &o, Point const &point );


#endif
