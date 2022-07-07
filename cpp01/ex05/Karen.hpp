#ifndef KAREN_HPP
# define KAREN_HPP

#include <iostream>

class Karen {
	private:
		void	base( void );
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
	public:
		void	complain( std::string level );
};

#endif
