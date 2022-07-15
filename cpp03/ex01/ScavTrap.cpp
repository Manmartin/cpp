#include <ScavTrap.hpp>

ScavTrap::ScavTrap( void ) : _hitpoints(100), _energy(50), _attack(20) {
	this->_name = "Default";
	std::cout << "ScavTrap " << this->_name << " has been created" << std::endl;
}

ScavTrap::ScavTrap( std::string const &name ) : _hitpoints(100), _energy(50), _attack(20) {
	this->_name = name;
	std::cout << "ScavTrap " << this->_name << " has been created" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const &ref ) : _attack(20) {
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
	return *this;
}

void	ScavTrap::attack( std::string const &target ) const {
	std::cout << "ScavTrap " << this->_name << " attack " << target 
	<< ", causing " << this->_attack << " points of damage!"
   	<< std::endl;
}

void	ScavTrap::guardGate( void ) {
	std::cout << "ScavTrap " << name << " have entered in Gate keeper mode"
	<< std::endl;
}
