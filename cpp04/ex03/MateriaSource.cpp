#include <MateriaSource.hpp>

MateriaSource::MateriaSource( void ): inventory() {
    std::cout << "Materia source created\n";
}

MateriaSource::MateriaSource( MateriaSource const &ref ): inventory() {
    std::cout << "Materia source created\n";
    *this = ref;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
	std::cout << "Materia source destroyed" << '\n';
}


MateriaSource const &MateriaSource::operator=( MateriaSource const &ref ) {
	std::cout << "Iguala\n";
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
		this->inventory[i] = ref.inventory[i] == NULL ? NULL : ref.inventory[i]->clone();
	}
	return	*this;
}

void    MateriaSource::learnMateria( AMateria* m ) {
    for (int i = 0; i < 4; i++)
		if (this->inventory[i] == NULL) {
			this->inventory[i] = m->clone();
			break;
	}
}

AMateria* MateriaSource::createMateria( std::string const & type ) {
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] && this->inventory[i]->getType() == type)
			return this->inventory[i]->clone();
	}
	return 0;
}
