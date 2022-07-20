#include <Brain.hpp>

Brain::Brain( void ) {
	std::cout << "Brain created" << std::endl;
}

Brain::Brain( Brain const &ref ) {
	*this = ref;
	std::cout << "Brain created" << std::endl;
}

Brain::~Brain( void ) {
	std::cout << "Brain destroyed" << std::endl;
}

Brain const &Brain::operator=( Brain const &ref ) {
	for (int i = 0; ref.ideas[i] != ""; i++)
		this->ideas[i] = ref.ideas[i];
	return *this;
}