#ifndef CURE_HPP
# define CURE_HPP

#include "includes.hpp"

class Cure: public AMateria {
    public:
        Cure( void );
        Cure( Cure const & other);
        ~Cure();

        Cure const  &operator=(Cure const &other);

        AMateria    *clone( void ) const;
        void        use( ICharacter& target );
};

#endif
