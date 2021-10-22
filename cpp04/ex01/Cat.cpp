#include "Cat.hpp"

/* Constructors and Destructor */

Cat::Cat( void ): Animal() {
    type = "Cat";
    brain = new Brain();
    std::cout << "Cat created" << std::endl;
}

Cat::Cat( Cat const &other ): Animal( other ) {
    *this = other;
    std::cout << "Cat created" << std::endl;
}

Cat::~Cat( void ) {
    delete  brain;
    std::cout << "Cat destroyed" << std::endl;
}


/* Operators Overload */

Cat const   &Cat::operator=( Cat const &other ) {
    type = other.type;
    brain = new Brain(*other.brain);
	return other;
}


/* Member Functions */

void	Cat::makeSound( void ) const{
    std::cout << "Meow Meow" << std::endl;
}

Brain   *Cat::getBrain( void ) const{
    return brain;
}
