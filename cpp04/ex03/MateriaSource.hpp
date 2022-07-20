#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <IMateriaSource.hpp>

class MateriaSource: public IMateriaSource {
    private:
        AMateria* inventory[4];

    public:
        MateriaSource( void );
        MateriaSource( MateriaSource const &ref );
        ~MateriaSource();

        MateriaSource const &operator=( MateriaSource const &ref );

        void learnMateria( AMateria* );
        AMateria* createMateria( std::string const & type );
};

#endif
