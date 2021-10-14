#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int	main(void) {
	int 	n_zombie;
	Zombie	*horde;

	n_zombie = 10;
	horde = zombieHorde(n_zombie, "Zombie");
	for (int i = 0; i < n_zombie; i++)
		horde[i].announce();
	delete [] horde;
	n_zombie = 5;
	horde = zombieHorde(n_zombie, "Hunter");
	for (int i = 0; i < n_zombie; i++)
		horde[i].announce();
	delete [] horde;
	n_zombie = 1;
	horde = zombieHorde(n_zombie, "Charger");
	for (int i = 0; i < n_zombie; i++)
		horde[i].announce();
	delete [] horde;
}