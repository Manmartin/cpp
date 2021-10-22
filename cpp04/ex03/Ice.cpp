#include "includes.hpp"

/* Constructors and destructor */

Ice::Ice( void ): AMateria( "ice" ) {}

Ice::Ice( Ice const &other ): AMateria( other ) {}

Ice::~Ice() {}


/* Operators' overload*/ 

Ice const  &Ice::operator=(Ice const &other) {
    (void)other;
    return  *this;
}


/* Member functions */

AMateria * Ice::clone( void ) const { return new Ice(); }

void    Ice::use( ICharacter& target) { std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl; }
