#include "Cat.hpp"

/* Constructors and Destructor */

Cat::Cat( void ): Animal() {
    type = "Cat";
    std::cout << "Cat created" << std::endl;
}

Cat::Cat( Cat const &other ): Animal( other ) {
    *this = other;
    std::cout << "Cat created" << std::endl;
}

Cat::~Cat( void ) {
    std::cout << "Cat destroyed" << std::endl;
}


/* Operators Overload */

Cat const   &Cat::operator=( Cat const &other ) {
    type = other.type;
	return other;
}


/* Member Functions */
void	Cat::makeSound( void ) const{
    std::cout << "Meow Meow" << std::endl;
}
