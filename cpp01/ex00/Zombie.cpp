#include <Zombie.hpp>

Zombie::Zombie( const std::string name) {
	_name = name;
}

Zombie::~Zombie( void ) {
	std::cout << _name << " died." << std::endl; 
}

void	Zombie::announce( void ) {
	std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
