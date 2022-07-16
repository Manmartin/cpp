#include <ScavTrap.hpp>

ScavTrap::ScavTrap( void ) {
	this->_hitpoints = 100;
	this->_energy = 50;
	this->_attack = 20;
	std::cout << "ScavTrap " << this->_name << " has been created" << std::endl;
}

ScavTrap::ScavTrap( std::string const &name ) : ClapTrap(name) {
	this->_hitpoints = 100;
	this->_energy = 50;
	this->_attack = 20;
	std::cout << "ScavTrap " << this->_name << " has been created" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const &ref ) : ClapTrap(ref._name) {
	*this = ref;
	std::cout << "ScavTrap " << this->_name << " has been created" << std::endl;
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "ScavTrap " << this->_name << " has been completely destroyed" << std::endl;
}

ScavTrap	&ScavTrap::operator=( ScavTrap const &ref ) {
	this->_name = ref._name;
	this->_hitpoints = ref._hitpoints;
	this->_energy = ref._energy;
	this->_attack = ref._attack;
	return *this;
}

void	ScavTrap::attack( std::string const &target ) const {
	std::cout << "ScavTrap " << this->_name << " attack " << target 
	<< ", causing " << this->_attack << " points of damage!"
   	<< std::endl;
}

void	ScavTrap::guardGate( void ) {
	std::cout << "ScavTrap " << this->_name << " have entered in Gate keeper mode"
	<< std::endl;
}
