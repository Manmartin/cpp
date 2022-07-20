#include <Character.hpp>
#include <MateriaSource.hpp>
#include <Ice.hpp>
#include <Cure.hpp>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

int main(void) {
	std::cout << BLUE << "Creating Materia Source\n\n" << RESET;
	std::cout << GREEN;
	IMateriaSource *src = new MateriaSource;
	std::cout << RESET << '\n';

	std::cout << BLUE << "Creating Materias\n\n" << RESET;


	std::cout << GREEN;
	AMateria	*a = new Ice();
	AMateria	*b = new Cure();
	std::cout << RESET << '\n';

	std::cout << BLUE << "Adding Materias to Materia Source\n\n" << RESET;
	std::cout << YELLOW << "* New materias are created because MateriaSource clone it *\n\n" << RESET;
	std::cout << GREEN;
	src->learnMateria(a);
	src->learnMateria(b);
	std::cout << RESET << '\n';


	std::cout << BLUE << "Destroying original materias using a pointer to AMateria\n\n" << RESET;	
	std::cout << RED;
	delete a;
	delete b;
	std::cout << RESET << '\n';


	std::cout << BLUE << "Creating character and using MateriaSource to add materias\n\n" << RESET;	
	std::cout << GREEN;

	ICharacter* me = new Character("me");
	AMateria* tmp;
	me->equip(src->createMateria("ice"));
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	std::cout << YELLOW << "\n* Materia for the other character *\n\n" << GREEN;
	bob->equip(src->createMateria("cure"));

	std::cout << YELLOW << '\n';
	me->use(0, *bob);
	me->use(1, *bob);

	me->unequip(1);
	me->use(1, *bob);

	/* Pruebas de funciones que no deberian hacer nada */
	me->unequip(1);
	me->use(80, *bob);
	me->use(2, *bob);
	src->createMateria("no existe");

	std::cout << "* Unequip a Materia dont delete it, but i going to destroy it anyway *\n\n" << RED;
	delete tmp;
	std::cout << RESET << '\n';


	std::cout << BLUE << "Trying Materia equal operator\n\n" << RESET;
	{
		std::cout << GREEN;
		Character a;
		Character b;
		std::cout << '\n';

		std::cout << YELLOW << "\n* Equiping a *\n\n" << GREEN;
		a.equip(src->createMateria("ice"));
		a.equip(src->createMateria("ice"));

		std::cout << YELLOW << "\n* Equiping b *\n\n" << GREEN;
		b.equip(src->createMateria("cure"));
		std::cout << '\n';

		std::cout << YELLOW << "\n* b = a *\n\n" << GREEN;
		b = a;
		std::cout << '\n';
		std::cout << RED;

	}
	std::cout << BLUE << "\nDeleting players and Material source\n\n" << RED;

	delete me;
	std::cout << '\n';
	delete bob;
	std::cout << '\n';
	delete src;
		std::cout << '\n';
	std::cout << RESET << '\n';
	return 0;
}
