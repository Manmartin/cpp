#include <Dog.hpp>

Dog::Dog( void ) {
	this->type = "Dog";
	std::cout << "Dog created" << std::endl;
}

Dog::Dog( Dog const &ref ) : Animal() {
	*this = ref;
	std::cout << "Dog created" << std::endl;
}

Dog::~Dog( void ) {
	std::cout << "Dog destroyed" << std::endl;
}

Dog const	&Dog::operator=( Dog const &ref ) {
	this->type = ref.type;
	return *this;
}

void		Dog::makeSound( void ) const {
	std::cout << "Woof" << std::endl;
}
