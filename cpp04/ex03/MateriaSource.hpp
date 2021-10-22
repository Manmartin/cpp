#ifndef MATERIALSOURCE_HPP
# define MATERIALSOURCE_HPP

#include "includes.hpp"

class IMateriaSource
{
    public:
        virtual ~IMateriaSource() {}
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};


class MateriaSource: public IMateriaSource{
    private:
       AMateria *_materias[4];
    public:
        MateriaSource( void );
        MateriaSource( MateriaSource const &other );
        ~MateriaSource();

        MateriaSource const &operator=(MateriaSource const &);

        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};


#endif 
