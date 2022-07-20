#include <Ice.hpp>

Ice::Ice( void ) : AMateria("ice") {
	std::cout << "Ice created" << '\n';
}

Ice::Ice( Ice const &ref ) : AMateria("ice") {
	std::cout << "Ice created" << '\n';
	*this = ref;
}

Ice::~Ice( void ) {
	std::cout << "Ice destroyed" << '\n';
}

Ice const &Ice::operator=( Ice const &ref ) {
	(void)ref;
	return *this;
}

AMateria	*Ice::clone() const {
	return new Ice();
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
