#ifndef DOG_HPP
# define DOG_HPP

#include <Animal.hpp>

class Dog: public Animal {

	public:
		Dog( void );
		Dog( Dog const &ref );
		~Dog( void );

		Dog const	&operator=( Dog const &ref );

		void	makeSound( void ) const;
};

#endif
