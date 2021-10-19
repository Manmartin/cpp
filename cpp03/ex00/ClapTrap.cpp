#include "ClapTrap.hpp"

/* Static  Variables*/


/* Constructors and Destructor */

ClapTrap::ClapTrap( void ) {
    _name = "Default";
    _hitpoints = 10;
    _energy_points = 10;
    _attack_damage = 0;
    std::cout << "ClapTrap " << _name << " has been created" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) {
    _name = name;
    _hitpoints = 10;
    _energy_points = 10;
    _attack_damage = 0;
    std::cout << "ClapTrap " << _name << " has been created" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const &other ) {
    *this = other;
    std::cout << "ClapTrap " << _name << " has been created" << std::endl;
}

ClapTrap::~ClapTrap(void) {
    std::cout << "ClapTrap " << _name << " has been completely destroyed" << std::endl;

}


/* Operators Overload */

ClapTrap const   &ClapTrap::operator=( ClapTrap const &other ) {
    _name = other._name;
    _hitpoints = other._hitpoints;
    _energy_points = other._energy_points;
    _attack_damage = other._attack_damage;
	return other;
}


/* Member Functions */

void    ClapTrap::attack( std::string const & target ) {
    std::cout << "ClapTrap " << _name << " attack " << target 
        << ", causing " << _attack_damage << " points of damage!"
        << std::endl;
}

void    ClapTrap::takeDamage( unsigned int amount ) {
    if (_hitpoints == 0) 
        std::cout << "ClapTrap " << _name << " is already destroyed" << std::endl;
    else if ( amount >= _hitpoints) {
        _hitpoints = 0;
        std::cout << "ClapTrap " << _name << " has been destroyed" << std::endl;
    }
    else {
        _hitpoints  -= amount;
        std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!"
        << std::endl
        << "Current hitpoints (" << _name << "): " << _hitpoints << std::endl;
    }
   
}

void    ClapTrap::beRepaired( unsigned int amount ) {
    _hitpoints += amount;
    std::cout << "ClapTrap " << _name << " has healed " << amount << " hitpoints"
    << std::endl
    << "Current hitpoints (" << _name << "): " << _hitpoints << std::endl;
}
