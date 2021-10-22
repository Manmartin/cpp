#include "Animal.hpp"

/* Constructors and Destructor */

Animal::Animal( void ) {
    type = "Animal";
    std::cout << "Animal created" << std::endl;
}

Animal::Animal( Animal const &other ) {
    *this = other;
    std::cout << "Animal created" << std::endl;
}

Animal::~Animal( void ) {
    std::cout << "Animal destroyed" << std::endl;
}


/* Operators Overload */

Animal const   &Animal::operator=( Animal const &other ) {
    type = other.type;
	return other;
}


/* Member Functions */

std::string Animal::getType( void ) const{
    return type;
}

void	Animal::makeSound( void ) const{
    std::cout << "???????" << std::endl;
}
