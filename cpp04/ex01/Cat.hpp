#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal {
	private:
		Brain	*brain;
	public:
	/* Constructors and destructor */

		Cat( void );
		Cat( Cat const &other );
		~Cat( void );

	/* operators overload */

		Cat const &operator=( Cat const &other );
	
	/* Member Functions */
		void	makeSound( void ) const;
		Brain	*getBrain( void ) const;
	
};

#endif