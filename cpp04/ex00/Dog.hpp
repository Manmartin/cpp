#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"

class Dog: public Animal {
	public:
	/* Constructors and destructor */

		Dog( void );
		Dog( Dog const &other );
		~Dog( void );

	/* operators overload */

		Dog const &operator=( Dog const &other );
	
	/* Member Functions */
		virtual void	makeSound( void ) const;
	
};

#endif