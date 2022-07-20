#include <Bureaucrat.hpp>
#include <Form.hpp>

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

	std::cout << BLUE << "Creating Goods Forms\n\n" << RESET;
	Form	base;
	Form	form("c24", 5, 120);
	std::cout << base << '\n';
	std::cout << form << '\n';
	std::cout << '\n';

	std::cout << BLUE << "Creating Bad Forms\n\n" << RESET;
	try {
		Form a("Too High", 0, 2);
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << '\n';
	}
	try {
		Form b("Too Low", 103, 255);
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << '\n';
	}
		try {
		Form a("Too High", 2, 0);
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << '\n';
	}
	try {
		Form b("Too Low", 255, 103);
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << '\n';
	}
	std::cout << '\n';

	std::cout << BLUE << "Sign Forms from Forms\n\n" << RESET;

	std::cout << YELLOW << "* " << min << " try to sign " << form << " *\n" << RESET;
	try {
		form.beSigned(&min);
	}
	catch(const std::exception& e) {
		std::cout << RED << e.what() << '\n';
	}
	std::cout << YELLOW << "* " << max << " try to sign " << form << " *\n" << RESET;
	form.beSigned(&max);
	std::cout << form << '\n';
	std::cout << '\n';

	Form newOne("new one",  25, 80);
	min.decrementGrade();
	std::cout << BLUE << "Sign Forms from Bureaucrats\n\n" << RESET;
	min.signForm(&newOne);
	min.signForm(&form);
	min.signForm(&base);
	std::cout << '\n';
	return 0;
}
