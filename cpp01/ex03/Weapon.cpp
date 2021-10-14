#include "Weapon.hpp"

Weapon::Weapon(std::string str) {
	_str = str;
}

Weapon::~Weapon(void) {
}

const std::string	Weapon::getType(void) {
	return (const std::string)_str;
}

void	Weapon::setType(std::string str) {
	_str = str;
}