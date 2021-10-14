#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int	main(void) {
	Zombie	zombie = Zombie("main");
	Zombie 	*p_zombie = newZombie("heap");
	zombie.announce();
	p_zombie->announce();
	randomChump("stack");
	delete p_zombie;
	return (0);
}