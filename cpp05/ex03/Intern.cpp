#include <Intern.hpp>

Intern::Intern( void ) {}
Intern::Intern( Intern const &ref ) {*this = ref;}
Intern::~Intern() {}

Intern const &Intern::operator=( Intern const &ref ) {
	(void)ref;
	return *this;
}

Form	*Intern::makeForm( std::string const &request, std::string const &target ) {
	int i = 0;
	std::string form_names[3] = {"shrubbery creation request", "robotomy request", "presidential pardon request"};
	Form *(*functions[4])(std::string const &target) = { ShrubberyCreationForm::clone, RobotomyRequestForm::clone, PresidentialPardonForm::clone, NULL};

	while (i < 3 && form_names[i] != request)
		i++;
	if (NULL == functions[i]) {
		std::cout << "Intern can't recognice this request: " << request << '\n';
		return NULL;
	}
	return functions[i](target);
}
