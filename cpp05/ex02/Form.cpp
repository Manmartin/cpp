#include <Form.hpp>

Form::Form( void ) : name("a1"), sign_grade(LOWER), exec_grade(LOWER), isSigned(false) {}
Form::Form( Form const &ref ) : name(ref.name), sign_grade(ref.sign_grade), exec_grade(ref.exec_grade), isSigned(ref.isSigned) {}
Form::~Form() {}

Form::Form( std::string const &name, int sign_grade, int exec_grade ) : name(name), sign_grade(sign_grade), exec_grade(exec_grade), isSigned(false) {
	if (this->sign_grade < HIGHER)
		throw Form::GradeTooHighException();
	else if (this->sign_grade > LOWER)
		throw Form::GradeTooLowException();
	if (this->exec_grade < HIGHER)
		throw Form::GradeTooHighException();
	else if (this->exec_grade > LOWER)
		throw Form::GradeTooLowException();
}


Form const	&Form::operator=( Form const &ref ) {
	(void)ref;
	return *this;
}


std::string	const Form::getName( void ) const {
	return this->name;
}

int Form::getSignGrade( void ) const {
	return this->sign_grade;
}

int Form::getExecGrade( void ) const {
	return this->exec_grade;
}

bool Form::getSign( void ) const {
	return this->isSigned;
}

void	Form::beSigned( Bureaucrat const &bur ) {
	if (this->isSigned)
		std::cout << "Form already signed\n";
	else if (bur.getGrade() <= this->sign_grade)
		this->isSigned = true;
	else
		throw Form::GradeTooLowException();
}


const char* Form::GradeTooLowException::what() const throw(){
	return "grade is too low";
}

const char* Form::GradeTooHighException::what() const throw(){
	return "grade is too high";
}

const char* Form::FormNotSignedException::what() const throw() {
	return "form is not signed";
}

std::ostream	&operator<<( std::ostream &o, Form const &ref ) {
	std::cout << ref.getName() << ", form: Sign(" << ref.getSignGrade() << ") Exec("  << ref.getExecGrade() << ") (" << (ref.getSign() ? "Signed" : "Unsigned") << ")";
	return o;
}
