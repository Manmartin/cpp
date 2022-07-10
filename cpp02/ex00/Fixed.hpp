#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					_value;
		static const int	_fractional_bits = 8;

	public:
		Fixed( void );
		Fixed( Fixed const &ref );
		~Fixed( void );
	
		Fixed	&operator=( Fixed const &ref );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif
