#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
	protected:
		std::string	type;
	public:
		WrongAnimal( void );
		WrongAnimal( WrongAnimal const &ref );
		~WrongAnimal( void );

		WrongAnimal const	&operator=( WrongAnimal const &ref );

		std::string const	&getType( void ) const;
		void				makeSound( void ) const;
};

#endif
