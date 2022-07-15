#include <ClapTrap.hpp>

int main(void) {
	std::cout << "[ Constructors test ]" << std::endl;
    std::cout << std::endl;
    ClapTrap    a( "player" );
    ClapTrap    b( a );
    ClapTrap    c;
    std::cout << std::endl;

    std::cout << "[ Attack tests ]" << std::endl;
    std::cout << std::endl;
    a.attack( "norminnete" );
    b.attack( "TIG" );
    c.attack( "segfault" );
    std::cout << std::endl;

    std::cout << "[ Damage tests ]" << std::endl;
    std::cout << std::endl;
    a.takeDamage( 8 );
    std::cout << std::endl;
    a.takeDamage( 5 );
    std::cout << std::endl;
    c.takeDamage( 200 );
    std::cout << std::endl;
    c.takeDamage( 200 );
    std::cout << std::endl;

    std::cout << "[ Heal tests ]" << std::endl;
    std::cout << std::endl;
    a.beRepaired( 8 );
    std::cout << std::endl;
    a.beRepaired( 10 );
    std::cout << std::endl;
    c.beRepaired( 15 );
    std::cout << std::endl;

    std::cout << "[ Destructor test ]" << std::endl;
    std::cout << std::endl;
}
