#include "Brain.hpp"

/* Constructors and Destructor */

Brain::Brain( void ) {
    index = 0;
    std::cout << "Brain created" << std::endl;
}

Brain::Brain( Brain const &other ) {
    *this = other;
    std::cout << "Brain created" << std::endl;
}

Brain::~Brain( void ) {
    std::cout << "Brain destroyed" << std::endl;
}

/* Operators Overload */

Brain const   &Brain::operator=( Brain const &other ) {
    index = other.index;
    for (unsigned int i = 0; i < index; i++) {
        ideas[i] = other.ideas[i];
    }
	return other;
}


/* Member Functions */

void    Brain::addIdea( std::string idea ) {
    if ( index >= 100)
        index = 0;
    ideas[index++] = idea;
}

std::string    Brain::getIdea( unsigned int i) {
    return ideas[i >= index ? index - 1 : i];
}

void    Brain::printIdeas( void ) {
    for (unsigned int i = 0; i < index; i++) {
        std::cout << ideas[i] << std::endl;
    }
}
