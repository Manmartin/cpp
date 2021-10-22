#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal {
	protected:
		std::string type;
	public:
	/* Constructors and destructor */

		WrongAnimal( void );
		WrongAnimal( WrongAnimal const &other );
		~WrongAnimal( void );

	/* operators overload */

		WrongAnimal const &operator=( WrongAnimal const &other );
	
	/* Member Functions */
		std::string	getType( void ) const;
		void	makeSound( void ) const;
	
};

#endif