#include <Bureaucrat.hpp>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

int main(void) {
	std::cout << BLUE << "Creating Goods Bureaucrats\n\n" << RESET;
	Bureaucrat min;
	Bureaucrat max("Higher", 1);
	std::cout << min << '\n';
	std::cout << max << '\n';
	std::cout << '\n';

	std::cout << BLUE << "Creating Bad Bureaucrats\n\n" << RESET;
	try {
		Bureaucrat max("Higher", 0);
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << '\n';
	}
	try {
		Bureaucrat max("Lower", 151);
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << '\n';
	}
	std::cout << '\n';

	std::cout << BLUE << "Incrementing and decrementing beyond limits\n\n" << RESET;
	try {
		max.incrementGrade();
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << '\n';
	}
	try {
		min.decrementGrade();
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << '\n';
	}
	std::cout << '\n';

	std::cout << BLUE << "Incrementing and decrementing inside limits\n\n" << RESET;
	max.decrementGrade();
	min.incrementGrade();
	std::cout << min << '\n';
	std::cout << max << '\n';
	std::cout << '\n';
	return 0;
}
