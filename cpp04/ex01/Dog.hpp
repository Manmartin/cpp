#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal {
	private:
		Brain	*brain;
	public:
	/* Constructors and destructor */

		Dog( void );
		Dog( Dog const &other );
		~Dog( void );

	/* operators overload */

		Dog const &operator=( Dog const &other );
	
	/* Member Functions */
		void	makeSound( void ) const;
		Brain	*getBrain( void ) const;
	
};

#endif