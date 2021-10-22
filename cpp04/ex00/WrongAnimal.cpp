#include "WrongAnimal.hpp"

/* Constructors and Destructor */

WrongAnimal::WrongAnimal( void ) {
    type = "WrongAnimal";
    std::cout << "WrongAnimal created" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const &other ) {
    *this = other;
    std::cout << "WrongAnimal created" << std::endl;
}

WrongAnimal::~WrongAnimal( void ) {
    std::cout << "WrongAnimal destroyed" << std::endl;
}


/* Operators Overload */

WrongAnimal const   &WrongAnimal::operator=( WrongAnimal const &other ) {
    type = other.type;
	return other;
}


/* Member Functions */

std::string WrongAnimal::getType( void ) const{
    return type;
}

void	WrongAnimal::makeSound( void ) const{
    std::cout << "???????" << std::endl;
}
