#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

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

	{
		std::cout << "[ New Battle ]" << std::endl;
		std::cout << std::endl;

		FragTrap	a( "Good Boy" );
		ScavTrap	b( "Bad Boy" );

		
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
		a.attack(b.name);
		b.takeDamage(a.attack_damage);
		std::cout << std::endl;
		a.highFives();
		std::cout << std::endl;
		std::cout << "[ Destructor ( new battle ) ]" << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "[ DiamondTrap test ]" << std::endl;
		std::cout << std::endl;
		DiamondTrap a( "Diamond" );
		std::cout << std::endl;
		std::cout << "[ ScavTrap's attack function and energy points with FragTrap's attack damage ]"<< std::endl;
		a.attack( "norminette" );
		std::cout << std::endl;
		a.takeDamage(50);
		std::cout << std::endl;
		a.beRepaired(50);
		std::cout << std::endl;
		a.highFives();
		std::cout << std::endl;
		a.guardGate();
		std::cout << std::endl;
		a.whoAmI();
		std::cout << std::endl;
		std::cout << "[ DiamondTrap destructor ]" << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "[ Destructor ( battle ) ]" << std::endl;
	std::cout << std::endl;

	return 0;
}