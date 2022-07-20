#ifndef INTERN_HPP
# define INTERN_HPP

#include <Form.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>

class Intern
{
	private:
		
	public:
		Intern( void );
		Intern( Intern const &ref );
		~Intern();

		Intern const &operator=( Intern const &ref );

		Form	*makeForm( std::string const &request, std::string const &target );
};

#endif
