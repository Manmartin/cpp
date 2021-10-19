#include "ClapTrap.hpp"

/* Static  Variables*/


/* Constructors and Destructor */

ClapTrap::ClapTrap( void ) {
    name = "Default";
    hitpoints = 10;
    energy_points = 10;
    attack_damage = 0;
    std::cout << "ClapTrap " << name << " has been created" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) {
    this->name = name;
    hitpoints = 10;
    energy_points = 10;
    attack_damage = 0;
    std::cout << "ClapTrap " << name << " has been created" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const &other ) {
    *this = other;
    std::cout << "ClapTrap " << name << " has been created" << std::endl;
}

ClapTrap::~ClapTrap(void) {
    std::cout << "ClapTrap " << name << " has been completely destroyed" << std::endl;

}


/* Operators Overload */

ClapTrap const   &ClapTrap::operator=( ClapTrap const &other ) {
    name = other.name;
    hitpoints = other.hitpoints;
    energy_points = other.energy_points;
    attack_damage = other.attack_damage;
	return other;
}


/* Member Functions */

void    ClapTrap::attack( std::string const & target ) {
    if (energy_points >= 10) {
        energy_points -= 10;
        std::cout << name << " attack " << target 
        << ", causing " << attack_damage << " points of damage!"
        << std::endl
        << "Remaining energy (" << name << "): " << energy_points
        << std::endl;
    }
    else
        std::cout << name << " doesn't have enough energy points to attack" << std::endl;

}

void    ClapTrap::takeDamage( unsigned int amount ) {
    if (hitpoints == 0)
        std::cout << name << " is already destroyed" << std::endl;
    else if ( amount >= hitpoints) {
        hitpoints = 0;
        std::cout << name << " has been destroyed" << std::endl;
    }
    else {
        hitpoints  -= amount;
        std::cout << name << " takes " << amount << " points of damage!"
            << std::endl;
        std::cout << "Current hitpoints (" << name << "): " << hitpoints << std::endl;
    }
}

void    ClapTrap::beRepaired( unsigned int amount ) {
    hitpoints += amount;
    std::cout << name << " has healed " << amount << " hitpoints"
    << std::endl
    << "Current hitpoints (" << name << "): " << hitpoints << std::endl;
}
