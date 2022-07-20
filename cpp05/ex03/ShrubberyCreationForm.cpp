#include <ShrubberyCreationForm.hpp>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm( void ) : Form("ShrubberyCreation", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm( std::string const &target ) : Form("ShrubberyCreation", 145, 137), target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const &ref ) : Form("ShrubberyCreation", 145, 137) {
	*this = ref;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm const &ShrubberyCreationForm::operator=( ShrubberyCreationForm const &ref ) {
	(void)ref;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (this->getSign() == false)
		throw Form::FormNotSignedException();
	else if (executor.getGrade() > this->getExecGrade())
		throw Form::GradeTooLowException();
	else {
		std::fstream file;
		std::string	fileName = this->target + "_shrubbery";
		std::string trees = "\
       ###\n\
      #o###\n\
    #####o###\n\
   #o#\\#|#/###\n\
    ###\\|/#o#\n\
     # }|{  #\n\
       }|{\n\
\n\
       ###\n\
      #o###\n\
    #####o###\n\
   #o#\\#|#/###\n\
    ###\\|/#o#\n\
     # }|{  #\n\
       }|{\n\
";


		file.open(fileName.c_str(), std::ios::out);
		if (!file)
			std::cout << "The input file could not be opened\n";
		else {
			file << trees;
			file.close();
		}
	}
}

Form	*ShrubberyCreationForm::clone( std::string const &target ) {
	return new ShrubberyCreationForm(target);
}
