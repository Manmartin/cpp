#include "DiamondTrap.hpp"

/* Static  Variables*/


/* Constructors and Destructor */

DiamondTrap::DiamondTrap( void ): ClapTrap() {
    name = "default";
    hitpoints = FragTrap::hitpoints;
    energy_points = ScavTrap::energy;
    attack_damage = FragTrap::attack_damage;
    std::cout << "DiamondTrap " << name << " has been created" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ): ClapTrap(name + "_clap_name") {
    this->name = name;
    hitpoints = FragTrap::hitpoints;
    energy_points = ScavTrap::energy;
    attack_damage = FragTrap::attack_damage;
    std::cout << "DiamondTrap " << name << " has been created" << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const &other ): ClapTrap( other ) {
    *this = other;
    std::cout << "DiamondTrap " << name << " has been created" << std::endl;
}

DiamondTrap::~DiamondTrap( void ) {
    std::cout << "DiamondTrap " << name << " has been completely destroyed" << std::endl;
}


/* Operators Overload */

DiamondTrap const   &DiamondTrap::operator=( DiamondTrap const &other ) {
    name = other.name;
    ClapTrap::name = name + "_clap_name";
    hitpoints = other.hitpoints;
    energy_points = other.energy_points;
    attack_damage = other.attack_damage;
	return other;
}


/* Member Functions */

void    DiamondTrap::whoAmI( void ) {
    std::cout << "Am I " << name << " or " << ClapTrap::name << "?"
    << std::endl;
}
