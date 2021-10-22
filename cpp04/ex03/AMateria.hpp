#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "includes.hpp"

class ICharacter;

class AMateria {
    private:
        AMateria();
    protected:
        std::string type;
    public:
        AMateria( std::string const & type );
        AMateria( AMateria const &other );
        virtual ~AMateria();

        AMateria const &operator=(AMateria const &);

        std::string const & getType( void ) const;
        virtual AMateria * clone( void ) const = 0;
        virtual void use(ICharacter& target);

};

#endif