#include <Dog.hpp>
#include <Cat.hpp>
#include <WrongCat.hpp>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

int main(void) {
	{
		std::cout << BLUE << "Animal test" << RESET << std::endl << std::endl;

		std::cout << GREEN <<  "[ Constructors test ]" << RESET << std::endl;
		std::cout << std::endl;
		const Animal* meta = new Animal();
		std::cout << std::endl;
		const Animal* j = new Dog();
		std::cout << std::endl;
		const Animal* i = new Cat();
		std::cout << std::endl;

		std::cout << GREEN <<  "[ getType test ]" << RESET << std::endl;
		std::cout << std::endl;		
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << std::endl;

		std::cout << GREEN <<  "[ makeSound test ]" << RESET << std::endl;
		std::cout << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();
		std::cout << std::endl;

		std::cout << RED << "[ Destructor test ]" << std::endl;
		std::cout << std::endl;
		delete meta;
		std::cout << std::endl;
		delete j;
		std::cout << std::endl;
		delete i;
	}
	std::cout << RESET << std::endl << std::endl;
	
	{
		std::cout << BLUE << "WrongAnimal test" << RESET << std::endl << std::endl;
		
		std::cout << GREEN <<  "[ Constructors test ]" << RESET << std::endl;
		const WrongCat* otag = new WrongCat();
		std::cout << std::endl;
		const WrongAnimal* meta = new WrongAnimal();
		std::cout << std::endl;
		const WrongAnimal* i = new WrongCat();
		std::cout << std::endl;

		std::cout << GREEN <<  "[ getType test ]" << RESET << std::endl;
		std::cout << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << std::endl;

		std::cout << GREEN <<  "[ makeSound test ]" << RESET << std::endl;
		std::cout << std::endl;
		otag->makeSound();
		meta->makeSound();
		i->makeSound();
		std::cout << std::endl;

		std::cout << RED << "[ Destructor test ]" << std::endl;
		std::cout << std::endl;
		delete otag;
		std::cout << std::endl;
		delete meta;
		std::cout << std::endl;
		delete i;
	}
	std::cout << RESET << std::endl << std::endl;

	return 0;
}