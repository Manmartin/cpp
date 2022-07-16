#include <DiamondTrap.hpp>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

int main( void ) {
	std::cout << BLUE << "ClapTrap test" << RESET << std::endl << std::endl;
	{
		std::cout << GREEN <<  "[ Constructors test ]" << RESET << std::endl;
		std::cout << std::endl;
		ClapTrap    a( "player" );
		ClapTrap    b( a );
		ClapTrap    c;
		std::cout << std::endl;

		std::cout << GREEN <<  "[ Attack tests ]" << RESET << std::endl;
		std::cout << std::endl;
		a.attack( "norminnete" );
		b.attack( "TIG" );
		c.attack( "segfault" );
		std::cout << std::endl;

		std::cout << GREEN <<  "[ Damage tests ]" << RESET << std::endl;
		std::cout << std::endl;
		a.takeDamage( 8 );
		std::cout << std::endl;
		a.takeDamage( 5 );
		std::cout << std::endl;
		c.takeDamage( 200 );
		std::cout << std::endl;
		c.takeDamage( 200 );
		std::cout << std::endl;

		std::cout << GREEN <<  "[ Heal test ]" << RESET << std::endl;
		std::cout << std::endl;
		a.beRepaired( 8 );
		std::cout << std::endl;
		a.beRepaired( 10 );
		std::cout << std::endl;
		c.beRepaired( 15 );
		std::cout << std::endl;

		std::cout << RED << "[ Destructor test ]" << std::endl;
		std::cout << std::endl;
	}
	std::cout << RESET << std::endl << std::endl;

	std::cout << BLUE << "ScavTrap test" << RESET << std::endl << std::endl;
	{
		std::cout << GREEN <<  "[ Constructors test ]" << RESET << std::endl;
		std::cout << std::endl;
		ScavTrap	a("NewScav");
		std::cout << std::endl;
		ScavTrap	b( a );
		std::cout << std::endl;
		ScavTrap	c;
		std::cout << std::endl;
		
		std::cout << GREEN <<  "[ Attack tests ]" << RESET << std::endl;
		std::cout << std::endl;
		a.attack( "norminnete" );
		b.attack( "TIG" );
		c.attack( "segfault" );
		std::cout << std::endl;

		std::cout << GREEN <<  "[ Damage tests ]" << RESET << std::endl;
		std::cout << std::endl;
		a.takeDamage( 85 );
		std::cout << std::endl;
		a.takeDamage( 15 );
		std::cout << std::endl;
		c.takeDamage( 200 );
		std::cout << std::endl;
		c.takeDamage( 200 );
		std::cout << std::endl;

		std::cout << GREEN <<  "[ Heal test ]" << RESET << std::endl;
		std::cout << std::endl;
		a.beRepaired( 8 );
		std::cout << std::endl;
		a.beRepaired( 10 );
		std::cout << std::endl;
		c.beRepaired( 15 );
		std::cout << std::endl;

		std::cout << GREEN <<  "[ Guard Gate test ]" << RESET << std::endl;
		std::cout << std::endl;
		a.guardGate();
		c.guardGate();
		std::cout << std::endl;

		std::cout << RED << "[ Destructor test ]" << std::endl;
		std::cout << std::endl;
	}
	std::cout << RESET << std::endl << std::endl;

	std::cout << BLUE << "DiamondTrap test" << RESET << std::endl << std::endl;
	{
		std::cout << GREEN <<  "[ Constructors test ]" << RESET << std::endl;
		std::cout << std::endl;
		DiamondTrap	a("Diamond");
		std::cout << std::endl;
		DiamondTrap	b( a );
		std::cout << std::endl;
		DiamondTrap	c;
		std::cout << std::endl;
		
		std::cout << GREEN <<  "[ Attack tests ]" << RESET << std::endl;
		std::cout << std::endl;
		a.attack( "norminnete" );
		b.attack( "TIG" );
		c.attack( "segfault" );
		std::cout << std::endl;

		std::cout << GREEN <<  "[ Damage tests ]" << RESET << std::endl;
		std::cout << std::endl;
		a.takeDamage( 25 );
		std::cout << std::endl;
		a.takeDamage( 15 );
		std::cout << std::endl;
		c.takeDamage( 200 );
		std::cout << std::endl;
		c.takeDamage( 200 );
		std::cout << std::endl;

		std::cout << GREEN <<  "[ Heal test ]" << RESET << std::endl;
		std::cout << std::endl;
		a.beRepaired( 8 );
		std::cout << std::endl;
		a.beRepaired( 10 );
		std::cout << std::endl;
		c.beRepaired( 15 );
		std::cout << std::endl;

		std::cout << GREEN <<  "[ Guard Gate test ]" << RESET << std::endl;
		std::cout << std::endl;
		a.guardGate();
		c.guardGate();
		std::cout << std::endl;

		std::cout << GREEN <<  "[ High Fives test ]" << RESET << std::endl;
		std::cout << std::endl;
		a.highFivesGuys();
		c.highFivesGuys();
		std::cout << std::endl;

		
		std::cout << GREEN <<  "[ WhoAmI test ]" << RESET << std::endl;
		std::cout << std::endl;
		a.whoAmI();
		c.whoAmI();
		std::cout << std::endl;

		std::cout << RED << "[ Destructor test ]" << std::endl;
		std::cout << std::endl;
	}
	std::cout << RESET << std::endl << std::endl;

	return 0;
}