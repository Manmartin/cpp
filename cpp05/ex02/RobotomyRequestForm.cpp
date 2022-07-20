#include <RobotomyRequestForm.hpp>
#include <cstdlib>


RobotomyRequestForm::RobotomyRequestForm( void ) : Form("RobotomyRequest", 72, 45), target("default") {}

RobotomyRequestForm::RobotomyRequestForm( std::string const &target ) : Form("RobotomyRequest", 72, 45), target(target) {
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &ref ) : Form("RobotomyRequest", 72, 45) {
	*this = ref;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm const &RobotomyRequestForm::operator=( RobotomyRequestForm const &ref ) {
	(void)ref;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (this->getSign() == false)
		throw Form::FormNotSignedException();
	else if (executor.getGrade() > this->getExecGrade())
		throw Form::GradeTooLowException();
	else {
		std::cout << "*Bzzzzzzzzz*\n";
		if (rand() % 2 == 0)
			std::cout << this->target << " has been robotomized successfully\n";
		else
			std::cout <<  this->target << " robotomization goes wrong\n";
	}
}
