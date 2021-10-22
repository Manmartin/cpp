#include "includes.hpp"

Character::Character( void ) {}

Character::Character( std::string name): _name(name) {
    for (int i = 0; i < 4; i++)
         _inventory[i] = 0;
}

Character::Character( Character &other) { *this = other; }

Character::~Character( void ) {
    for (int i = 0; i < 4; i++) {
        if (_inventory[i])
            delete _inventory[i];
    }
}


/* Operation Overload*/

Character  &Character::operator=(Character &other) {
    _name = other._name;
    for (int i = 0; i < 4; i++)
        if (_inventory[i])
            delete _inventory[i];
    for (int i = 0; i < 4; i++)
        _inventory[i] = other._inventory[i] ? other._inventory[i]->clone() : 0;
    return *this;
}


/* Member Functions */

std::string const   &Character::getName( void ) const { return _name; }

void    Character::equip( AMateria *m) {
    for (int i = 0; i < 4; i++) {
        if (!_inventory[i]) { 
            _inventory[i] = m;
            break;
        }
    }
}

void    Character::unequip( int idx ) {
    if (idx >= 0 && idx <= 3 && _inventory[idx])
        _inventory[idx] = 0;
}

void    Character::use( int idx, ICharacter& target ) {
        if (idx >= 0 && idx <= 3 && _inventory[idx])
            _inventory[idx]->use(target);
}
