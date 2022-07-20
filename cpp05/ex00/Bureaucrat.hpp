#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define LOWER 150
# define HIGHER 1

# include <iostream>

class Bureaucrat {
	private:
		std::string	const name;
		int	grade;
	public:
		Bureaucrat( void );
		Bureaucrat( Bureaucrat const & ref );
		Bureaucrat( std::string const &name, int grade );
		~Bureaucrat();

		Bureaucrat const &operator=( Bureaucrat const &ref );

		std::string	const getName( void ) const;
		int getGrade( void ) const;

		void incrementGrade( void );
		void decrementGrade( void );

		class GradeTooHighException: public std::exception {
			virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			virtual const char* what() const throw(); 
		};
};

std::ostream	&operator<<( std::ostream &o, Bureaucrat const &ref );

#endif
