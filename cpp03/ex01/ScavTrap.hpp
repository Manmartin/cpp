#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
	private:

	public:
	/* Constructors and destructor */

		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( ScavTrap const &other );
		~ScavTrap( void );

	/* operators overload */

		ScavTrap const &operator=( ScavTrap const &other );
	
	/* member functions */
	void	guardGate( void );

};

#endif