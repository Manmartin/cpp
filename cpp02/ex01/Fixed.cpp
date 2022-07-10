#include <Fixed.hpp>

Fixed::Fixed( void ) {
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed( Fixed const &ref ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = ref;
}

Fixed::Fixed( int const value ) {
	std::cout << "Int constructor called" << std::endl;
	this->_value = value << Fixed::_fractional_bits;
}

Fixed::Fixed( float const value ) {
	std::cout << "Float constructor called" << std::endl;
	this->_value = (int)roundf(value * (1 << Fixed::_fractional_bits));
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}


Fixed	&Fixed::operator=( Fixed const &ref ) {
	std::cout << "Assignation operator called" << std::endl;
	this->_value = ref._value;
	return *this;
}


int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

int		Fixed::toInt( void ) const {
	return this->_value >> Fixed::_fractional_bits;
}

float	Fixed::toFloat( void ) const {
	return (float)this->_value / (1 << Fixed::_fractional_bits);
}


std::ostream	&operator<<( std::ostream &o, Fixed const &ref ) {
	o << ref.toFloat();
	return o;
}
