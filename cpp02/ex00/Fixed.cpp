#include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;


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


Fixed	&Fixed::operator=( Fixed const &instance ) {
	std::cout << "Assignation operator called" << std::endl;
	_value = instance.getRawBits();
	return *this;
}


int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}
