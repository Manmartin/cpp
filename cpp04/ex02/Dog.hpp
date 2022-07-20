#ifndef DOG_HPP
# define DOG_HPP

#include <Animal.hpp>
#include <Brain.hpp>

class Dog: public Animal {
	private:
		Brain	*brain;
	public:
		Dog( void );
		Dog( Dog const &ref );
		~Dog( void );

		Dog const	&operator=( Dog const &ref );

		void	makeSound( void ) const;
		void	addIdea( std::string const &idea );
		std::string const getIdea( unsigned int n );
};

#endif
