#ifndef ICE_HPP
# define ICE_HPP

#include "includes.hpp"

class Ice: public AMateria {
    public:
        Ice( void );
        Ice( Ice const & other);
        ~Ice();

        Ice const  &operator=(Ice const &other);

        AMateria    *clone( void ) const;
        void        use( ICharacter& target );
};

#endif