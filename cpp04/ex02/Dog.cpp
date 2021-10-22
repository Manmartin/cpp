#include "Dog.hpp"

/* Constructors and Destructor */

Dog::Dog( void ): Animal() {
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog created" << std::endl;
}

Dog::Dog( Dog const &other ): Animal( other ) {
    *this = other;
    std::cout << "Dog created" << std::endl;
}

Dog::~Dog( void ) {
    delete  brain;
    std::cout << "Dog destroyed" << std::endl;
}

/* Operators Overload */

Dog const   &Dog::operator=( Dog const &other ) {
    type = other.type;
    brain = new Brain(*other.brain);
	return other;
}

/* Member Functions */
void	Dog::makeSound( void ) const{
    std::cout << "Woof" << std::endl;
}

Brain   *Dog::getBrain( void ) const{
    return  brain;
}
