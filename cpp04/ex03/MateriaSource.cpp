#include "includes.hpp"

MateriaSource::MateriaSource( void ) {
    for (int i = 0; i < 4; i++)
        _materias[i] = 0;
}

MateriaSource::MateriaSource( MateriaSource const &other ) { *this = other; }


MateriaSource::~MateriaSource( void ) {
    for (int i = 0; i < 4; i++)
        if (_materias[i])
            delete _materias[i];
}


/* Operators' overload */

MateriaSource const &MateriaSource::operator=(MateriaSource const &other) {
    for (int i = 0; i < 4; i++)
        if (_materias[i])
            delete _materias[i];
    for (int i = 0; i < 4; i++)
        _materias[i] = other._materias[i] ? other._materias[i]->clone() : 0;
    return *this;
}


/* Member Functions */ 

void    MateriaSource::learnMateria( AMateria *m) {
    for (int i = 0; i < 4; i++) {
        if (!_materias[i]) {
            _materias[i] = m;
            break;
        }
    }
}

AMateria    *MateriaSource::createMateria(std::string const & type) {
    for (int i = 0;i < 4; i++)
        if ( _materias[i] && type == _materias[i]->getType())
            return  _materias[i]->clone();
    return 0;
}
