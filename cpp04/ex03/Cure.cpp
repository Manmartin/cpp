#include <Cure.hpp>

Cure::Cure( void ) : AMateria("cure") {
	std::cout << "Cure created" << '\n';
}

Cure::Cure( Cure const &ref ) : AMateria("cure") {
	std::cout << "Cure created" << '\n';
	*this = ref;
}

Cure::~Cure( void ) {
	std::cout << "Cure destroyed" << '\n';
}

Cure const &Cure::operator=( Cure const &ref ) {
	(void)ref;
	return *this;
}

AMateria	*Cure::clone() const {
	return new Cure();
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << " wounds *\n";
}

