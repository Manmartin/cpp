#include <WrongAnimal.hpp>

WrongAnimal::WrongAnimal( void ) : type("WrongAnimal") {
	std::cout << "WrongAnimal created" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const &ref ) {
	*this = ref;
	std::cout << "WrongAnimal created" << std::endl;
}

WrongAnimal::~WrongAnimal( void ) {
	std::cout << "WrongAnimal destroyed" << std::endl;
}

WrongAnimal const	&WrongAnimal::operator=( WrongAnimal const &ref ) {
	this->type = ref.type;
	return *this;
}

std::string const	&WrongAnimal::getType( void ) const {
	return this->type;
}

void		WrongAnimal::makeSound( void ) const {
	std::cout << "!!!!!!!!!!!" << std::endl;
}
