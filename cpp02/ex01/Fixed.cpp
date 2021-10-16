#include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;

/* Constructors and destructor */

Fixed::Fixed( void ) {
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( Fixed const &instance ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = instance;
}

Fixed::Fixed( int const value) {
	std::cout << "Int constructor called" << std::endl;
	_value = value << _fractional_bits;
}

Fixed::Fixed( float const value) {
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(value * (1 << _fractional_bits));
}


/* Operators overload */

Fixed	&Fixed::operator=( Fixed const &instance ) {
	std::cout << "Assignation operator called" << std::endl;
	_value = instance.getRawBits();
	return *this;
}

std::ostream	&operator<<( std::ostream &o, Fixed const &instance ) {
	o << (float)instance.getRawBits() / 256;
	return o;
}


/* Member functions */

int	Fixed::getRawBits( void ) const {
	return _value;
}

void	Fixed::setRawBits( int const raw ) {
	_value = raw;
}

int		Fixed::toInt( void ) const {
	return  _value >> _fractional_bits;
}

float	Fixed::toFloat (void) const {
	return (float)_value / 256;
}