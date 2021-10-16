#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {

	private:

	int 				_value;
	static	const int	_fractional_bits;

	public:

		Fixed( void );
		~Fixed( void );
		Fixed( Fixed const &instance );

		Fixed	&operator=( Fixed const & instance );
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

};

#endif