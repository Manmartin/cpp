#include "WrongCat.hpp"

/* Constructors and Destructor */

WrongCat::WrongCat( void ): WrongAnimal() {
    type = "WrongCat";
    std::cout << "WrongCat created" << std::endl;
}

WrongCat::WrongCat( WrongCat const &other ): WrongAnimal( other ) {
    *this = other;
    std::cout << "WrongCat created" << std::endl;
}

WrongCat::~WrongCat( void ) {
    std::cout << "WrongCat destroyed" << std::endl;
}


/* Operators Overload */

WrongCat const   &WrongCat::operator=( WrongCat const &other ) {
    type = other.type;
	return other;
}


/* Member Functions */
void	WrongCat::makeSound( void ) const{
    std::cout << "Meow Meow" << std::endl;
}
