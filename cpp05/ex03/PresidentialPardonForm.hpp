#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <Form.hpp>

class PresidentialPardonForm: public Form {
	private:
		std::string const target;

	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( std::string const &target );
		PresidentialPardonForm( PresidentialPardonForm const &ref );
		~PresidentialPardonForm();

		PresidentialPardonForm const &operator=( PresidentialPardonForm const &ref );

		void execute(Bureaucrat const & executor) const;
		static Form *clone( std::string const &target );
};

#endif
