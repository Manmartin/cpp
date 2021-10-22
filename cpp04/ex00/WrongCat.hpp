#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include <string>
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
	public:
	/* Constructors and destructor */

		WrongCat( void );
		WrongCat( WrongCat const &other );
		~WrongCat( void );

	/* operators overload */

		WrongCat const &operator=( WrongCat const &other );
	
	/* Member Functions */
		void	makeSound( void ) const;
	
};

#endif