#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main () {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	const WrongAnimal* WrongMeta = new WrongAnimal();
	const WrongAnimal* WrongJ = new WrongCat();
	std::cout << std::endl;

	std::cout << WrongMeta->getType() << " " << std::endl;
	std::cout << WrongJ->getType() << " " << std::endl;
	std::cout << std::endl;

	WrongMeta->makeSound();
	WrongJ->makeSound();
	std::cout << std::endl;

	delete WrongMeta;
	delete WrongJ;
	std::cout << std::endl;




	delete meta;
	delete j;
	delete i;
	return 0;
}
