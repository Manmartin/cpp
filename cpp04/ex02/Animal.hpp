#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal {
	protected:
		std::string type;
	public:
	/* Constructors and destructor */

		Animal( void );
		Animal( Animal const &other );
		virtual ~Animal( void );

	/* operators overload */

		Animal const &operator=( Animal const &other );
	
	/* Member Functions */
		std::string	getType( void ) const;
		virtual void	makeSound( void ) const = 0;
	
};

#endif