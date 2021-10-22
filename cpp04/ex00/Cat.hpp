#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"

class Cat: public Animal {
	public:
	/* Constructors and destructor */

		Cat( void );
		Cat( Cat const &other );
		~Cat( void );

	/* operators overload */

		Cat const &operator=( Cat const &other );
	
	/* Member Functions */
		virtual void	makeSound( void ) const;
	
};

#endif