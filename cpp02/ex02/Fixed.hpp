#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {

	private:

	int 				_value;
	static const int	_fractional_bits;

	public:

		Fixed( void );
		~Fixed( void );
		Fixed( Fixed const &instance );
		Fixed( int const value );
		Fixed( float const value );

		Fixed	&operator=( Fixed const & instance );
		Fixed	&operator++( void );
		Fixed	operator++( int );
		Fixed	&operator--( void );
		Fixed	operator--( int );

		Fixed	operator+( Fixed const &instance ) const;
		Fixed	operator-( Fixed const &instance ) const;
		Fixed	operator*( Fixed const & instance ) const;
		Fixed	operator/( Fixed const & instance ) const;

		bool	operator>( Fixed const & instance ) const;
		bool	operator<( Fixed const & instance ) const;
		bool	operator>=( Fixed const & instance ) const;
		bool	operator<=( Fixed const & instance ) const;
		bool	operator==( Fixed const & instance ) const;
		bool	operator!=( Fixed const & instance ) const;


		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		int		toInt( void ) const;
		float	toFloat( void ) const;

		static Fixed		&min( Fixed &f1, Fixed &f2);
		static Fixed const	&min( Fixed const &f1, Fixed const &f2);
		static Fixed		&max( Fixed &f1, Fixed &f2);
		static Fixed const	&max( Fixed const &f1, Fixed const &f2);



};

std::ostream &operator<<( std::ostream &o, Fixed const &instance );

#endif