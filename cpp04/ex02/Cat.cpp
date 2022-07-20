#include <Cat.hpp>

Cat::Cat( void ) {
	std::cout << "Cat created" << std::endl;
	this->brain = new Brain();
	this->type = "Cat";
}

Cat::Cat( Cat const &ref ) : Animal() {
	std::cout << "Cat created" << std::endl;
	this->brain = new Brain();
	*this = ref;
}

Cat::~Cat( void ) {
	delete this->brain;
	std::cout << "Cat destroyed" << std::endl;
}

Cat const	&Cat::operator=( Cat const &ref ) {
	this->type = ref.type;
	*this->brain = *ref.brain;
	return *this;
}

void		Cat::makeSound( void ) const {
	std::cout << "Meow" << std::endl;
}

void	Cat::addIdea( std::string const &idea ) {
	for (int i = 0; i < 100; i++) {
		if (this->brain->ideas[i] == "") {
			this->brain->ideas[i] = idea;
			break;
		}
	}
}

std::string const Cat::getIdea( unsigned int n ) {
	return	n < 100 ? this->brain->ideas[n] : std::string("");
}
