#include <PresidentialPardonForm.hpp>

PresidentialPardonForm::PresidentialPardonForm( void ) : Form("PresidentialPardon", 25, 5), target("default") {}

PresidentialPardonForm::PresidentialPardonForm( std::string const &target ) : Form("PresidentialPardon", 25, 5), target(target) {
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const &ref ) : Form("PresidentialPardon", 25, 5) {
	*this = ref;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm const &PresidentialPardonForm::operator=( PresidentialPardonForm const &ref ) {
	(void)ref;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (this->getSign() == false)
		throw Form::FormNotSignedException();
	else if (executor.getGrade() > this->getExecGrade())
		throw Form::GradeTooLowException();
	else
		std::cout << this->target <<  " has been pardoned by Zafod Beeblebrox.\n";
}

Form	*PresidentialPardonForm::clone( std::string const &target ) {
	return new PresidentialPardonForm(target);
}
