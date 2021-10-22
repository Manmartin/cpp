#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>


class Brain {
	private:
		unsigned int index;
	public:
	/*  Variables */ 
		std::string	ideas[100];
	/* Constructors and destructor */

		Brain( void );
		Brain( Brain const &other );
		~Brain( void );

	/* operators overload */

		Brain const &operator=( Brain const &other );
	
	/* Member Functions */
		void		addIdea( std::string idea );
		std::string	getIdea( unsigned int i );
		void		printIdeas( void );

};

#endif