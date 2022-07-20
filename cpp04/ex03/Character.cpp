#include <Character.hpp>

Character::Character( void ) : inventory() {
	std::cout << "Character created" << '\n';
	this->name = "Default";
}

Character::Character( std::string const &name ) : inventory() {
	std::cout << "Character created" << '\n';
	this->name = name;
}

Character::Character( Character const &ref ) : inventory() {
	std::cout << "Character created" << '\n';
	*this = ref;
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
	std::cout << "Character destroyed" << '\n';
}


Character const &Character::operator=( Character const &ref ) {
	this->name = ref.name;
	for (int i = 0; i < 4; i++) {
		delete this->inventory[i];
		this->inventory[i] = ref.inventory[i] == NULL ? NULL : 	ref.inventory[i]->clone();
	}
	return	*this;
}


std::string	const	&Character::getName( void ) const {
	return this->name;
}

void	Character::equip( AMateria* m ) {
	for (int i = 0; i < 4; i++)
		if (this->inventory[i] == NULL) {
			this->inventory[i] = m;
			break;
		}
}

void	Character::unequip( int idx ) {
	if (idx >= 0 && idx <= 3 && this->inventory[idx] != NULL)
		this->inventory[idx] = NULL;
}

void	Character::use( int idx, ICharacter& target ) {
	if (idx >= 0 && idx <= 3 && this->inventory[idx] != NULL)
		this->inventory[idx]->use(target); 
}
