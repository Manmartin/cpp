#include <DiamondTrap.hpp>

DiamondTrap::DiamondTrap( void ) : ClapTrap("default_clap_name") {
	this->_name = "default";
	this->_hitpoints = FragTrap::_hitpoints;
	this->_energy = ScavTrap::_energy;
	this->_attack = FragTrap::_attack;
	std::cout << "DiamondTrap " << this->_name << " has been created" << std::endl;
}

DiamondTrap::DiamondTrap( std::string const &name ) : ClapTrap(name + "_clap_name") {
	this->_name = name;
	this->_hitpoints = FragTrap::_hitpoints;
	this->_energy = ScavTrap::_energy;
	this->_attack = FragTrap::_attack;
	std::cout << "DiamondTrap " << this->_name << " has been created" << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const &ref ) : ClapTrap(ref._name + "_clap_name") {
	*this = ref;
	std::cout << "DiamondTrap " << this->_name << " has been created" << std::endl;
}

DiamondTrap::~DiamondTrap( void ) {
	std::cout << "DiamondTrap " << this->_name << " has been completely destroyed" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=( DiamondTrap const &ref ) {
	this->_name = ref._name;
	this->_hitpoints = ref._hitpoints;
	this->_energy = ref._energy;
	this->_attack = ref._attack;
	return *this;
}

void	DiamondTrap::whoAmI( void ) {
	std::cout << "Am I " << this->_name << " or " << ClapTrap::_name << "?"
    << std::endl;
}
