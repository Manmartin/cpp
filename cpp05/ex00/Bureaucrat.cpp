#include "Bureaucrat.hpp"


/* Error Clases*/

const char * Bureaucrat::GradeTooHighException::what() const throw(){
    return "\e[1;31mError: Grade can't be lower than 1\e[1;0m";
}

const char * Bureaucrat::GradeTooLowException::what() const throw(){
    return "\e[1;31mError: Grade can't be greater than 150\e[1;0m";

}

/* Constructors and Destructor */

Bureaucrat::Bureaucrat( std::string name, unsigned int grade ): _name(name) {

        if (grade > 150)
            throw GradeTooLowException();
        else if (grade < 1)
            throw GradeTooHighException();
        else
            _grade = grade;
}

Bureaucrat::Bureaucrat( Bureaucrat const &other ) { *this = other; }

Bureaucrat::~Bureaucrat( void ) {
}


/* Operators Overload */

Bureaucrat const   &Bureaucrat::operator=( Bureaucrat const &other ) {
    _grade = other._grade;
	return *this;
}


/* Member Functions */

std::string     Bureaucrat::getName( void )  const  { return _name; }

unsigned int    Bureaucrat::getGrade( void ) const  { return _grade; }

void            Bureaucrat::gradeUp( void ) {
    if (_grade == 1)
        throw GradeTooHighException();
    else
        _grade--;
}

void            Bureaucrat::gradeDown( void ) {
    if (_grade == 150)
        throw GradeTooLowException();
    else 
        _grade++;
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &instance) {
    o << instance.getName() << ", bureaucrat grade " << instance.getGrade();
    return o;
}
