#include <Dog.hpp>

Dog::Dog( void ) {
	std::cout << "Dog created" << std::endl;
	this->brain = new Brain();
	this->type = "Dog";
}

Dog::Dog( Dog const &ref ) : Animal() {
	std::cout << "Dog created" << std::endl;
	this->brain = new Brain();
	*this = ref;
}

Dog::~Dog( void ) {
	delete this->brain;
	std::cout << "Dog destroyed" << std::endl;
}

Dog const	&Dog::operator=( Dog const &ref ) {
	this->type = ref.type;
	*this->brain = *ref.brain;
	return *this;
}

void		Dog::makeSound( void ) const {
	std::cout << "Woof" << std::endl;
}

void	Dog::addIdea( std::string const &idea ) {
	for (int i = 0; i < 100; i++) {
		if (this->brain->ideas[i] == "") {
			this->brain->ideas[i] = idea;
			break;
		}
	}
}

std::string const Dog::getIdea( unsigned int n ) {
	return	n < 100 ? this->brain->ideas[n] : std::string("");
}
