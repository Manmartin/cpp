#ifndef CAT_HPP
# define CAT_HPP

#include <Animal.hpp>
#include <Brain.hpp>

class Cat: public Animal {
	private:
		Brain	*brain;
	public:
		Cat( void );
		Cat( Cat const &ref );
		~Cat( void );

		Cat const	&operator=( Cat const &ref );

		void	makeSound( void ) const;
		void	addIdea( std::string const &idea );
		std::string const getIdea( unsigned int n );
};

#endif
