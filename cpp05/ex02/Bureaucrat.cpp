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

void Bureaucrat::signForm( Form &form ) {
	try {
		if (form.getSign())
			std::cout << *this << " cannot sign " << form << " because is already signed\n";
		else {
			form.beSigned(*this);
			std::cout << *this << " signs " << form << '\n';
		}
	}
	catch(const std::exception& e) {
		std::cout << *this << " cannot sign " << form << " because " << e.what() << '\n';
	}
	
}

void Bureaucrat::executeForm(Form const & form) {
	try {
			form.execute(*this);
			std::cout << *this << " executes " << form << '\n';
	} catch(const std::exception& e) {
		std::cout << *this << " cannot execute " << form << " because " << e.what() << '\n';
	}
}



std::ostream	&operator<<( std::ostream &o, Bureaucrat const &ref ) {
	o << ref.getName() << ", bureaucrat grade " << ref.getGrade() << ".";
	return o;
}

/* Errors */

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "grade is too low";
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "grade is too high";
}
