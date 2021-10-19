#include "ScavTrap.hpp"

int main( void ) {
	std::cout << "[ Constructors test ]" << std::endl;
	std::cout << std::endl;
	ScavTrap	a( "Main Character" );
	{
		std::cout << std::endl;
		std::cout << "[ Copy constructor ]" << std::endl;
		ScavTrap	c( a );
	}
	std::cout << std::endl;
	ClapTrap	b( "Bad Guy" );
	std::cout << std::endl;

	std::cout << "[ Battle ]" << std::endl;
	std::cout << std::endl;
	b.attack( a.name );
	a.takeDamage(b.attack_damage);
	b.attack( a.name );
	std::cout << std::endl;
	a.attack(b.name);
	b.takeDamage(a.attack_damage);
	std::cout << std::endl;
	a.attack(b.name);
	b.takeDamage(a.attack_damage);
	std::cout << std::endl;
	b.beRepaired(20);
	a.attack(b.name);
	b.takeDamage(a.attack_damage);
	std::cout << std::endl;
	a.guardGate();
	std::cout << std::endl;

	std::cout << "[ Destructor test ]" << std::endl;
	std::cout << std::endl;

	return 0;
}