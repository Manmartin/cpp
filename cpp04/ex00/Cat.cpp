#include <Cat.hpp>

Cat::Cat( void ) {
	this->type = "Cat";
	std::cout << "Cat created" << std::endl;
}

Cat::Cat( Cat const &ref ) : Animal() {
	*this = ref;
	std::cout << "Cat created" << std::endl;
}

Cat::~Cat( void ) {
	std::cout << "Cat destroyed" << std::endl;
}

Cat const	&Cat::operator=( Cat const &ref ) {
	this->type = ref.type;
	return *this;
}

void		Cat::makeSound( void ) const {
	std::cout << "Meow" << std::endl;
}
