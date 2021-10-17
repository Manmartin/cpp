#include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;


/* Constructors and destructor */

Fixed::Fixed( void ) {
	_value = 0;
}

Fixed::~Fixed( void ) {
}

Fixed::Fixed( Fixed const &instance ) {
	*this = instance;
}

Fixed::Fixed( int const value) {
	_value = value << _fractional_bits;
}

Fixed::Fixed( float const value) {
	_value = roundf(value * (1 << _fractional_bits));
}


/* Operators overloads */

Fixed	&Fixed::operator=( Fixed const &instance ) {
	_value = instance.getRawBits();
	return *this;
}

Fixed	&Fixed::operator++( void ) {
	this->_value++;
	return	*this;
}

Fixed	Fixed::operator++( int ) {
	Fixed	temp(*this);

	this->_value++;
	return	temp;
}

Fixed	&Fixed::operator--( void ) {
	this->_value--;
	return	*this;
}

Fixed	Fixed::operator--( int ) {
	Fixed	temp(*this);

	this->_value--;
	return	temp;
}


Fixed	Fixed::operator+( Fixed const &instance ) const{
	return Fixed(this->toFloat() + instance.toFloat());
}

Fixed	Fixed::operator-( Fixed const &instance ) const{
	return Fixed(this->toFloat() - instance.toFloat());
}

Fixed	Fixed::operator*( Fixed const &instance ) const{
	return Fixed(this->toFloat() * instance.toFloat());
}

Fixed	Fixed::operator/( Fixed const & instance ) const{
	return Fixed(this->toFloat() / instance.toFloat());
}


/* Comparations overloads */

bool	Fixed::operator>( Fixed const & instance ) const{
	return (this->toFloat() > instance.toFloat());
}

bool	Fixed::operator<( Fixed const & instance ) const{
	return (this->toFloat() < instance.toFloat());
}

bool	Fixed::operator>=( Fixed const & instance ) const{
	return (this->toFloat() >= instance.toFloat());
}

bool	Fixed::operator<=( Fixed const & instance ) const{
	return (this->toFloat() <= instance.toFloat());
}

bool	Fixed::operator==( Fixed const & instance ) const{
	return (this->toFloat() == instance.toFloat());
}

bool	Fixed::operator!=( Fixed const & instance ) const{
	return (this->toFloat() != instance.toFloat());
}

/* Stream operator overload */
std::ostream	&operator<<( std::ostream &o, Fixed const &instance ) {
	o << (float)instance.toFloat();
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


/* Static functions */

Fixed	&Fixed::min( Fixed &f1, Fixed &f2) {
	return (f1 < f2 ? f1 : f2);
}

Fixed const	&Fixed::min( Fixed const &f1, Fixed const &f2) {
	return (f1 < f2 ? f1 : f2);
}

Fixed	&Fixed::max( Fixed &f1, Fixed &f2) {
	return (f1 > f2 ? f1 : f2);
}

Fixed const	&Fixed::max( Fixed const &f1, Fixed const &f2) {
	return (f1 > f2 ? f1 : f2);
}
