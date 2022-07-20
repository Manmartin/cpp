#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <Form.hpp>

class RobotomyRequestForm: public Form {
	private:
		std::string const target;

	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( std::string const &target );
		RobotomyRequestForm( RobotomyRequestForm const &ref );
		~RobotomyRequestForm();

		RobotomyRequestForm const &operator=( RobotomyRequestForm const &ref );

		void execute(Bureaucrat const & executor) const;
};

#endif
