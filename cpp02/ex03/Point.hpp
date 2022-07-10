#ifndef POINT_HPP
# define POINT_HPP

# include <Fixed.hpp>

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;
	public:
		Point( void );
		Point( Point const &ref );
		Point( float const x, float const y );
		~Point();

		Point const	&operator=( Point const &ref );
		Point	operator+( Point const &ref ) const ;
		Point	operator-( Point const &ref ) const ;
		Point	operator*( Point const &ref ) const ;
		Point	operator/( Point const &ref ) const ;

		Fixed const	&getX( void ) const;
		Fixed const	&getY( void ) const;

};

std::ostream &operator<<( std::ostream &o, Point const &point );

#endif
