#include <WrongCat.hpp>

WrongCat::WrongCat( void ) {
	this->type = "WrongCat";
	std::cout << "WrongCat created" << std::endl;
}

WrongCat::WrongCat( WrongCat const &ref ) : WrongAnimal() {
	*this = ref;
	std::cout << "WrongCat created" << std::endl;
}

WrongCat::~WrongCat( void ) {
	std::cout << "WrongCat destroyed" << std::endl;
}

WrongCat const	&WrongCat::operator=( WrongCat const &ref ) {
	this->type = ref.type;
	return *this;
}

void		WrongCat::makeSound( void ) const {
	std::cout << "Woem" << std::endl;
}
