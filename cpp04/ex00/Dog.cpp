#include "Dog.hpp"

/* Constructors and Destructor */

Dog::Dog( void ): Animal() {
    type = "Dog";
    std::cout << "Dog created" << std::endl;
}

Dog::Dog( Dog const &other ): Animal( other ) {
    *this = other;
    std::cout << "Dog created" << std::endl;
}

Dog::~Dog( void ) {
    std::cout << "Dog destroyed" << std::endl;
}


/* Operators Overload */

Dog const   &Dog::operator=( Dog const &other ) {
    type = other.type;
	return other;
}


/* Member Functions */
void	Dog::makeSound( void ) const{
    std::cout << "Woof" << std::endl;
}
