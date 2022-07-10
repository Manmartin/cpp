#include <Fixed.hpp>

Fixed::Fixed( void ) {
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed( Fixed const &ref ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = ref;
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
