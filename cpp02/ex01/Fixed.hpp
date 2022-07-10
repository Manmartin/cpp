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
		Fixed( void );
		Fixed( Fixed const &ref );
		Fixed( int const value );
		Fixed( float const value );
		~Fixed( void );
	
		Fixed	&operator=( Fixed const &ref );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		int		toInt( void ) const;
		float	toFloat( void ) const;

};

std::ostream	&operator<<(std::ostream &o, Fixed const &ref);

#endif
