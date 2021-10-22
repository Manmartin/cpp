#include "includes.hpp"

/* Constructor and Destructor */

AMateria::AMateria( std::string const & type ): type(type) {}

AMateria::AMateria ( AMateria const &other ): type(other.type) {}

AMateria::AMateria( void ) {}

AMateria::~AMateria( void ) {}


/* Operators' overload */

AMateria const &AMateria::operator=(AMateria const &other) {
    (void)other;
    return *this;
}

/* Functions */

std::string const & AMateria::getType( void ) const { return type; }

void    AMateria::use(ICharacter& target) { (void)target; }



