#include <AMateria.hpp>

AMateria::AMateria( std::string const & type ) {
	std::cout << "AMateria created" << '\n';
	this->type = type;
}

AMateria::~AMateria() {
	std::cout << "AMateria destroyed" << '\n';
}

std::string const &AMateria::getType( void ) const {
	return this->type;
}
