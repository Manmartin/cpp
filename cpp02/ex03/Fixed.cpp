#include <Fixed.hpp>

/* Constructors and destructor */

Fixed::Fixed( void ) {
	this->_value = 0;
}

Fixed::Fixed( Fixed const &ref ) {
	*this = ref;
}

Fixed::Fixed( int const value ) {
	this->_value = value << Fixed::_fractional_bits;
}

Fixed::Fixed( float const value ) {
	this->_value = (int)roundf(value * (1 << Fixed::_fractional_bits));
}

Fixed::~Fixed( void ) {
}

/* operators */

Fixed	&Fixed::operator++( void ) {
	++this->_value;
	return *this;
}

Fixed	Fixed::operator++( int n ) {
	Fixed	temp(*this);
	this->_value += n == 0 ? 1 : n; 
	return temp;
}

Fixed	&Fixed::operator--( void ) {
	--this->_value;
	return *this;
}

Fixed	Fixed::operator--( int n ) {
	Fixed	temp(*this);
	this->_value -= n == 0 ? 1 : n; 
	return temp;
}

Fixed	&Fixed::operator=( Fixed const &ref ) {
	this->_value = ref._value;
	return *this;
}

Fixed	Fixed::operator+( Fixed const &ref ) const {
	return Fixed(this->toFloat() + ref.toFloat());
}

Fixed	Fixed::operator-( Fixed const &ref ) const {
	return Fixed(this->toFloat() - ref.toFloat());
}

Fixed	Fixed::operator*( Fixed const &ref ) const {
	return Fixed(this->toFloat() * ref.toFloat());
}

Fixed	Fixed::operator/( Fixed const &ref ) const {
	return Fixed(this->toFloat() / ref.toFloat());
}

/* Comparations */ 

bool	Fixed::operator>( Fixed const &ref ) const {
	return this->_value > ref._value;
}

bool	Fixed::operator<( Fixed const &ref ) const {
	return this->_value < ref._value;
}

bool	Fixed::operator>=( Fixed const &ref ) const {
	return this->_value >= ref._value;
}

bool	Fixed::operator<=( Fixed const &ref ) const{
	return this->_value <= ref._value;
}

bool	Fixed::operator==( Fixed const &ref ) const {
	return this->_value == ref._value;
}

bool	Fixed::operator!=( Fixed const &ref ) const {
	return this->_value != ref._value;
}

/* Member functions */

int		Fixed::getRawBits( void ) const {
	return this->_value;
}

void	Fixed::setRawBits( int const raw ) {
	this->_value = raw;
}

int		Fixed::toInt( void ) const {
	return this->_value >> Fixed::_fractional_bits;
}

float	Fixed::toFloat( void ) const {
	return (float)this->_value / (1 << Fixed::_fractional_bits);
}

/* Non Member Functions */

Fixed	&Fixed::min( Fixed &ref1, Fixed &ref2 ) {
	return ref1 <= ref2 ? ref1 : ref2;
}

Fixed const	&Fixed::min( Fixed const &ref1, Fixed const &ref2 ) {
	return ref1 <= ref2 ? ref1 : ref2;
}

Fixed	&Fixed::max( Fixed &ref1, Fixed &ref2 ) {
	return ref1 >= ref2 ? ref1 : ref2;
}

Fixed const	&Fixed::max( Fixed const &ref1, Fixed const &ref2 ) {
	return ref1 >= ref2 ? ref1 : ref2;
}

std::ostream	&operator<<( std::ostream &o, Fixed const &ref ) {
	o << ref.toFloat();
	return o;
}
