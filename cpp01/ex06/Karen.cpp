#include "Karen.hpp"

Karen::Karen(void) {
	_functions[0] = base;
	_functions[1] = debug;
	_functions[2] = info;
	_functions[3] = warning;
	_functions[4] = error;

}

Karen::~Karen(void) {
}

void	Karen::base( void ) {
	std::cout << "[Probably complains about insignificant problems]" << std::endl;
}

void	Karen::debug( void ) {
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI just love it!" << std::endl;
}

void	Karen::info( void ) {
	std::cout << "I cannot believe adding extra bacon cost more money.\nYou don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void	Karen::warning( void ) {
	std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming here for years and you just started working here last month." << std::endl;
}

void	Karen::error( void ) {
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void 	Karen::complain(std::string level) {
	int index;
	std::istringstream(level) >> index;
	_functions[(index > 4 || index < 0 ? 0 : index)]();
}
