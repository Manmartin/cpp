#include <ClapTrap.hpp>

ClapTrap::ClapTrap( void ) : _hitpoints(10), _energy(10), _attack(0) {
	this->_name = "Default";
	std::cout << "ClapTrap " << this->_name << " has been created" << std::endl;
}

ClapTrap::ClapTrap( std::string const &name ) : _hitpoints(10), _energy(10), _attack(0) {
	this->_name = name;
	std::cout << "ClapTrap " << this->_name << " has been created" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const &ref ) : _attack(0) {
	*this = ref;
	std::cout << "ClapTrap " << this->_name << " has been created" << std::endl;
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "ClapTrap " << this->_name << " has been completely destroyed" << std::endl;
}

ClapTrap	&ClapTrap::operator=( ClapTrap const &ref ) {
	this->_name = ref._name;
	this->_hitpoints = ref._hitpoints;
	this->_energy = ref._energy;
	return *this;
}

void	ClapTrap::attack( std::string const &target ) const {
	std::cout << "ClapTrap " << this->_name << " attack " << target 
	<< ", causing " << this->_attack << " points of damage!"
   	<< std::endl;
}

void	ClapTrap::takeDamage( unsigned int amount ) {
	if (this->_hitpoints == 0) 
		std::cout << "ClapTrap " << this->_name << " is already destroyed" << std::endl;
	else if ( amount >= this->_hitpoints) {
		this->_hitpoints = 0;
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
		std::cout << "ClapTrap " << this->_name << " has been destroyed" << std::endl;
	}
	else {
		this->_hitpoints  -= amount;
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
		std::cout << "Current hitpoints (" << this->_name << "): " << this->_hitpoints << std::endl;
	}
}

void	ClapTrap::beRepaired( unsigned int amount ) {
	this->_hitpoints += amount;
	std::cout << "ClapTrap " << this->_name << " has healed " << amount << " hitpoints"
	<< std::endl
	<< "Current hitpoints (" << this->_name << "): " << this->_hitpoints << std::endl;
}
