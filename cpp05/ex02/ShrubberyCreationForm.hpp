#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <Form.hpp>

class ShrubberyCreationForm: public Form {
	private:
		std::string const target;

	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( std::string const &target );
		ShrubberyCreationForm( ShrubberyCreationForm const &ref );
		~ShrubberyCreationForm();

		ShrubberyCreationForm const &operator=( ShrubberyCreationForm const &ref );

		void execute(Bureaucrat const & executor) const;
};

#endif
