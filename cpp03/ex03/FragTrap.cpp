#include "FragTrap.hpp"

/* Static  Variables*/
    const unsigned int FragTrap::life = 100;
    const unsigned int FragTrap::energy = 100;
    const unsigned int FragTrap::damage = 30;



/* Constructors and Destructor */

FragTrap::FragTrap( void ): ClapTrap() {
    hitpoints = life;
    energy_points = energy;
    attack_damage = damage;
    std::cout << "FragTrap " << name << " has been created" << std::endl;
}

FragTrap::FragTrap( std::string name ): ClapTrap( name ) {
    hitpoints = life;
    energy_points = energy;
    attack_damage = damage;
    std::cout << "FragTrap " << name << " has been created" << std::endl;
}

FragTrap::FragTrap( FragTrap const &other ): ClapTrap( other ) {
    *this = other;
    std::cout << "FragTrap " << name << " has been created" << std::endl;
}

FragTrap::~FragTrap( void ) {
    std::cout << "FragTrap " << name << " has been completely destroyed" << std::endl;
}


/* Operators Overload */

FragTrap const   &FragTrap::operator=( FragTrap const &other ) {
    name = other.name;
    hitpoints = other.hitpoints;
    energy_points = other.energy_points;
    attack_damage = other.attack_damage;
	return other;
}


/* Member Functions */

void    FragTrap::highFives( void ) {
    std::cout << "FragTrap " << name << " says \"High Fives!\""
    << std::endl;
}
