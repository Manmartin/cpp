#include <FragTrap.hpp>

FragTrap::FragTrap( void ) {
	this->_hitpoints = 100;
	this->_energy = 100;
	this->_attack = 30;
	std::cout << "FragTrap " << this->_name << " has been created" << std::endl;
}

FragTrap::FragTrap( std::string const &name ) : ClapTrap(name) {
	this->_hitpoints = 100;
	this->_energy = 100;
	this->_attack = 30;
	std::cout << "FragTrap " << this->_name << " has been created" << std::endl;
}

FragTrap::FragTrap( FragTrap const &ref ) : ClapTrap(ref._name) {
	*this = ref;
	std::cout << "FragTrap " << this->_name << " has been created" << std::endl;
}

FragTrap::~FragTrap( void ) {
	std::cout << "FragTrap " << this->_name << " has been completely destroyed" << std::endl;
}

FragTrap	&FragTrap::operator=( FragTrap const &ref ) {
	this->_name = ref._name;
	this->_hitpoints = ref._hitpoints;
	this->_energy = ref._energy;
	this->_attack = ref._attack;
	return *this;
}

void	FragTrap::attack( std::string const &target ) const {
	std::cout << "FragTrap " << this->_name << " attack " << target 
	<< ", causing " << this->_attack << " points of damage!"
   	<< std::endl;
}

void	FragTrap::highFivesGuys( void ) {
	std::cout << "FragTrap " << this->_name << " says \"High Fives!\""
	<< std::endl;
}
