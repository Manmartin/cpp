#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					_value;
		static const int	_fractional_bits = 8;

	public:
		/* Constructor and Destructor */
		Fixed( void );
		Fixed( Fixed const &ref );
		Fixed( int const value );
		Fixed( float const value );
		~Fixed( void );
	
		/* Operators */
		Fixed	&operator++( void );
		Fixed	operator++( int n );
		Fixed	&operator--( void );
		Fixed	operator--( int n );

		Fixed	&operator=( Fixed const &ref );
		Fixed	operator+( Fixed const &ref ) const;
		Fixed	operator-( Fixed const &ref ) const;
		Fixed	operator*( Fixed const &ref ) const;
		Fixed	operator/( Fixed const &ref ) const;
	
		bool	operator>( Fixed const &ref ) const;
		bool	operator<( Fixed const &ref ) const;
		bool	operator>=( Fixed const &ref ) const;
		bool	operator<=( Fixed const &ref ) const;
		bool	operator==( Fixed const &ref ) const;
		bool	operator!=( Fixed const &ref ) const;

		/* Member Functions */
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		int		toInt( void ) const;
		float	toFloat( void ) const;

		/* Non Member Functions */
		static Fixed	&min( Fixed &ref1, Fixed &ref2 );
		static Fixed	&max( Fixed &ref1, Fixed &ref2 );
		static Fixed const	&min( Fixed const &ref1, Fixed const &ref2 );
		static Fixed const	&max( Fixed const &ref1, Fixed const &ref2 );
};

std::ostream	&operator<<(std::ostream &o, Fixed const &ref);

#endif
