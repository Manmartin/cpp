#include "ScavTrap.hpp"

/* Static  Variables*/
    const unsigned int ScavTrap::life = 100;
    const unsigned int ScavTrap::energy = 50;
    const unsigned int ScavTrap::damage = 20;

/* Constructors and Destructor */

ScavTrap::ScavTrap( void ): ClapTrap() {
    hitpoints = life;
    energy_points = energy;
    attack_damage = damage;
    std::cout << "ScavTrap " << name << " has been created" << std::endl;
}

ScavTrap::ScavTrap( std::string name ): ClapTrap( name ) {
    hitpoints = life;
    energy_points = energy;
    attack_damage = damage;
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

void    ScavTrap::attack( std::string const & target ) {
    if (energy_points >= 10) {
        energy_points -= 10;
        std::cout << "ScavTrap " << name << " attack " << target 
        << ", causing " << attack_damage << " points of damage!"
        << std::endl
        << "Remaining energy (" << name << "): " << energy_points
        << std::endl;
    }
    else
        std::cout << "ScavTrap " << name << " doesn't have enough energy points to attack"
        << std::endl;
}

void    ScavTrap::guardGate( void ) {
    std::cout << "ScavTrap " << name << " have entered in Gate keeper mode"
    << std::endl;
}
