#ifndef FORM_HPP
# define FORM_HPP

# define LOWER 150
# define HIGHER 1

# include <iostream>
# include <Bureaucrat.hpp>

class Bureaucrat;

class Form {
	private:
		std::string const name;
		int	const sign_grade;
		int const exec_grade;
		bool isSigned;

	public:
		Form( void );
		Form( Form const &ref );
		Form( std::string const &name, int sign_grade, int exec_grade );
		virtual ~Form();

		Form const	&operator=( Form const &ref );

		std::string	const getName( void ) const;
		int getSignGrade( void ) const;
		int getExecGrade( void ) const;
		bool getSign( void ) const;
		
		void	beSigned( Bureaucrat const & bur );
		virtual void execute(Bureaucrat const & executor) const = 0;
	
		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const throw(); 
		};
		class FormNotSignedException: public std::exception {
			public:
				virtual const char* what() const throw(); 
		};
};

std::ostream	&operator<<( std::ostream &o, Form const &ref ); 

#endif
