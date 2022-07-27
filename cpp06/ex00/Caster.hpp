#ifndef CASTER_HPP
# define CASTER_HPP

# include <iostream>
# include <cstdlib>
# include <limits>
# include <math.h>

class Caster {
	private:
		std::string _rawValue;
		static const char *special[7]; 
		union {
			char	c;
			double	nb;
			const char	*special;
		} value;
		enum { CHAR, DOUBLE, SPECIAL, ERROR } type;
	public:
		Caster( void );
		Caster( Caster const &ref );
		~Caster( void );

		Caster const &operator=( Caster const &ref );

		void	setRawValue( std::string const &rawValue );
		std::string const &getRawValue( void );
		void	castValue( void );

		bool	isSpecial( std::string const &ref );
		bool	isException( void );

		void	printChar( int c, char const *special );
		void	printInt( int nb, char const *special );
		void	printFloat( float nbf, char const *special );
		void	printDouble( double nbd, char const *special );
		

		void	castFromChar( void );
		void	castFromDouble( void );
		void	castFromSpecial( void );
		void	castError( void );
};

#endif
