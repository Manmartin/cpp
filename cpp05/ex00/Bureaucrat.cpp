#include <Bureaucrat.hpp>

Bureaucrat::Bureaucrat( void ) : name("Lower"), grade(150) {
}

Bureaucrat::Bureaucrat( Bureaucrat const &ref ) : name(ref.name) {
	*this = ref;
}

Bureaucrat::Bureaucrat( std::string const &name, int grade) : name(name) {
	if (grade < HIGHER)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > LOWER)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::~Bureaucrat() {}


Bureaucrat const &Bureaucrat::operator=( Bureaucrat const &ref ) {
	this->grade = ref.grade;
	return *this;
}


std::string	const Bureaucrat::getName( void ) const {
	return this->name;
}

int Bureaucrat::getGrade( void ) const {
	return this->grade;
}

void	Bureaucrat::incrementGrade( void ) {
	if (this->grade - 1 < HIGHER)
		throw Bureaucrat::GradeTooHighException();
	--this->grade;
}

void	Bureaucrat::decrementGrade( void ) {
	if (this->grade + 1 > LOWER)
		throw Bureaucrat::GradeTooLowException();
	++this->grade;
}

std::ostream	&operator<<( std::ostream &o, Bureaucrat const &ref ) {
	o << ref.getName() << ", bureaucrat grade " << ref.getGrade() << ".";
	return o;
}

/* Errors */

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade can't be lower than 150";
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade can't be higher than 1";
}
