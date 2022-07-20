#include <Animal.hpp>

Animal::Animal( void ) : type("Animal") {
	std::cout << "Animal created" << std::endl;
}

Animal::Animal( Animal const &ref ) {
	*this = ref;
	std::cout << "Animal created" << std::endl;
}

Animal::~Animal( void ) {
	std::cout << "Animal destroyed" << std::endl;
}

Animal const	&Animal::operator=( Animal const &ref ) {
	this->type = ref.type;
	return *this;
}

std::string const	&Animal::getType( void ) const {
	return this->type;
}

void		Animal::makeSound( void ) const {
	std::cout << "????????" << std::endl;
}
