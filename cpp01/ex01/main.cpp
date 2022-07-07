#include <Zombie.hpp>

int main(void) {
	int		n_zombie;
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

	n_zombie = 0;
	horde = zombieHorde(n_zombie, "No one");
	for (int i = 0; i < n_zombie; i++)
		horde[i].announce();
	delete [] horde;

	return 0;
}
