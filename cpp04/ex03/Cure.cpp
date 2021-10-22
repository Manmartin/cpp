#include "includes.hpp"

/* Constructors and destructor */

Cure::Cure( void ): AMateria( "cure" ) {}

Cure::Cure( Cure const &other ): AMateria( other ) {}

Cure::~Cure() {}


/* Operators' overload*/ 

Cure const  &Cure::operator=(Cure const &other) {
    (void)other;
    return  *this;
}


/* Member functions */

AMateria * Cure::clone( void ) const { return new Cure(); }

void    Cure::use( ICharacter& target) { std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl; }
