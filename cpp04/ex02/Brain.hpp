#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	public:
		std::string	ideas[100];
		Brain( void );
		Brain( Brain const &ref );
		~Brain( void );

		Brain const	&operator=( Brain const &ref );

};

#endif
