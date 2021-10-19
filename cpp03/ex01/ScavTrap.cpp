#include "ScavTrap.hpp"

/* Static  Variables*/


/* Constructors and Destructor */

ScavTrap::ScavTrap( void ): ClapTrap() {
    hitpoints = 100;
    energy_points = 50;
    attack_damage = 20;
    std::cout << "ScavTrap " << name << " has been created" << std::endl;
}

ScavTrap::ScavTrap( std::string name ): ClapTrap( name ) {
    hitpoints = 100;
    energy_points = 50;
    attack_damage = 20;
    std::cout << "ScavTrap " << name << " has been created" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const &other ): ClapTrap( other ) {
    *this = other;
    std::cout << "ScavTrap " << name << " has been created" << std::endl;
}

ScavTrap::~ScavTrap( void ) {
    std::cout << "ScavTrap " << name << " has been completely destroyed" << std::endl;
}


/* Operators Overload */

ScavTrap const   &ScavTrap::operator=( ScavTrap const &other ) {
    name = other.name;
    hitpoints = other.hitpoints;
    energy_points = other.energy_points;
    attack_damage = other.attack_damage;
	return other;
}


/* Member Functions */

void    ScavTrap::guardGate( void ) {
    std::cout << "ScavTrap " << name << " have entered in Gate keeper mode"
    << std::endl;
}
