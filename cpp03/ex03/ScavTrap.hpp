#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public virtual ClapTrap {
	private:

	public:
		static const unsigned int life;
		static const unsigned int energy;
		static const unsigned int damage;

	/* Constructors and destructor */

		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( ScavTrap const &other );
		~ScavTrap( void );

	/* operators overload */

		ScavTrap const &operator=( ScavTrap const &other );
	
	/* member functions */
	void	attack( std::string const & target );
	void	guardGate( void );

};

#endif