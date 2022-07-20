#include <Dog.hpp>
#include <Cat.hpp>

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
		std::cout << std::endl;

		std::cout << RED << "[ Destructor test ]" << std::endl;
		std::cout << std::endl;
		delete j;
		std::cout << std::endl;
		delete i;
	}
	std::cout << RESET << std::endl << std::endl;

	{
		std::cout << BLUE << "Deep copy test with dogs" << RESET << std::endl << std::endl;

		std::cout << GREEN <<  "[ original dog ]" << RESET << std::endl;
		std::cout << std::endl;
		Dog	original;
		std::cout << std::endl;
		original.addIdea("Wooooof");
		original.addIdea("Is a good time to bark");

		std::cout << YELLOW <<  "* original ideas *" << RESET << std::endl;
		for (int i = 0; original.getIdea(i) != ""; i++)
			std::cout << original.getIdea(i) <<std::endl;
		std::cout << std::endl;
		{
			std::cout << GREEN <<  "[ copy dog ]" << RESET << std::endl;
			std::cout << std::endl;
			Dog	copy( original );
			std::cout << std::endl;

			std::cout << YELLOW <<  "* New idea added to copy dog *" << RESET << std::endl;
			std::cout << std::endl;
			copy.addIdea("I want to bite a bone");
			for (int i = 0; copy.getIdea(i) != ""; i++)
				std::cout << copy.getIdea(i) <<std::endl;
			std::cout << RED << std::endl;
		}
		std::cout << RESET << std::endl;
		std::cout << YELLOW <<  "* original ideas again *" << RESET << std::endl;
		for (int i = 0; original.getIdea(i) != ""; i++)
			std::cout << original.getIdea(i) <<std::endl;
		std::cout << std::endl;
		std::cout << RED << std::endl;
	}
	std::cout << RESET << std::endl;

	{
		std::cout << BLUE << "Deep copy test with cats" << RESET << std::endl << std::endl;

		std::cout << GREEN <<  "[ original cat ]" << RESET << std::endl;
		std::cout << std::endl;
		Cat	original;
		std::cout << std::endl;
		original.addIdea("Meow Meow");
		original.addIdea("I hate all of you");

		std::cout << YELLOW <<  "* original ideas *" << RESET << std::endl;
		for (int i = 0; original.getIdea(i) != ""; i++)
			std::cout << original.getIdea(i) <<std::endl;
		std::cout << std::endl;
		{
			std::cout << GREEN <<  "[ copy cat ]" << RESET << std::endl;
			std::cout << std::endl;
			Cat	copy( original );
			std::cout << std::endl;

			std::cout << YELLOW <<  "* New idea added to copy cat *" << RESET << std::endl;
			std::cout << std::endl;
			copy.addIdea("Nice box");
			for (int i = 0; copy.getIdea(i) != ""; i++)
				std::cout << copy.getIdea(i) <<std::endl;
			std::cout << RED << std::endl;
		}
		std::cout << RESET << std::endl;
		std::cout << YELLOW <<  "* original ideas again *" << RESET << std::endl;
		for (int i = 0; original.getIdea(i) != ""; i++)
			std::cout << original.getIdea(i) <<std::endl;
		std::cout << std::endl;
		std::cout << RED << std::endl;
	}
	std::cout << RESET << std::endl;

	{
		int n = 2;
		std::cout << BLUE << "Virtual destructor test" << RESET << std::endl << std::endl;
		Animal const *animals[n];
		for (int i = 0; i < n/2; i++)
				animals[i] = new Dog();
		std::cout << std::endl;
		for (int i = n/2; i < n; i++)
				animals[i] = new Cat();
		std::cout << std::endl;
		for (int i = 0; i < n; i++)
			animals[i]->makeSound();
		std::cout << RED << std::endl;
		for (int i = 0; i < n; i++)
			delete animals[i];	
	}
	std::cout << RESET << std::endl << std::endl;
	return 0;
}