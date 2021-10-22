#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat {

	private:
		Bureaucrat( void );

		std::string const _name;
		unsigned int	  _grade;

	public:
	/* Constructors and destructor */

		Bureaucrat( std::string name, unsigned int grade );
		Bureaucrat( Bureaucrat const &other );
		~Bureaucrat( void );

	/* operators overload */

		Bureaucrat const &operator=( Bureaucrat const &other );
	/* Member Functions */
		std::string		getName( void ) const;
		unsigned int	getGrade( void ) const;
		void			gradeUp( void );
		void			gradeDown( void );
	/* Error Clases*/

		class GradeTooHighException: public std::exception {
			public:
				virtual const char *what( void ) const throw();

		};

		class GradeTooLowException: public std::exception { 
			public:
				virtual const char *what( void ) const throw();
		};

};

std::ostream	&operator<<( std::ostream &o, Bureaucrat const &instance );


#endif