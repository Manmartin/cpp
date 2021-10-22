#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main (void) {
	const Animal** animals = new const Animal*[100];
	int limit = 4;

	std::cout << "\e[1;35m[ Constructor test ]\e[1;32m" << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < limit; i++) {
		if (i < limit / 2)
			animals[i] = new const Dog();
		else
			animals[i] = new const Cat();
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "\e[1;34m[ Brain test ]\e[1;36m" << std::endl;
		std::cout << std::endl;
		Brain	*original_brain = ((Dog *)animals[0])->getBrain();

		original_brain->addIdea("Bark a cat");
		original_brain->addIdea("Eat grass");
		std::cout << "Original brain's ideas:" << std::endl;
		std::cout << std::endl;
		original_brain->printIdeas();
		std::cout << std::endl;

		std::cout << "Creating a dog's clone...\e[1;32m" << std::endl;
		std::cout << std::endl;
		const Dog	*clone_dog = new const Dog(*(Dog *)animals[0]);
		Brain	*clone_brain = clone_dog->getBrain();
		std::cout << std::endl;

		std::cout << "\e[1;36mBrain's Clone's ideas:" << std::endl;
		std::cout << std::endl;
		clone_brain->printIdeas();
		std::cout << std::endl;

		std::cout << "Adding new ideas:" << std::endl;
		std::cout << std::endl;
		clone_brain->addIdea("Bark a butterfly");
		clone_brain->printIdeas();
		std::cout << std::endl;
	
		std::cout << "\e[1;34m[ Brain comparison ]\e[1;36m" << std::endl;
		std::cout << std::endl;
		std::cout << "Original brain:" << std::endl;
		std::cout << std::endl;
		original_brain->printIdeas();
		std::cout << std::endl;
		std::cout << "Brain's clone:" << std::endl;
		std::cout << std::endl;
		clone_brain->printIdeas();
		std::cout << std::endl;

		std::cout << "\e[1;31m[ Destructor test 1 ]\e[1;33m" << std::endl;
		std::cout << std::endl;
		delete	clone_dog;
	}
	std::cout << std::endl;
	std::cout << "\e[1;31m[ Destructor test 2 ]\e[1;33m" << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < limit; i++) {
		delete animals[i];
		std::cout << std::endl;
	}
	std::cout << "\e[1;0m";
	delete [] animals;
	return 0;
}
