#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
	private:


	public:

		std::string	name;
		unsigned int hitpoints;
		unsigned int energy_points;
		unsigned int attack_damage;

	/* Constructors and destructor */

		ClapTrap( void );
		ClapTrap( std::string name );
		ClapTrap( ClapTrap const &other );
		~ClapTrap( void );

	/* operators overload */

		ClapTrap const &operator=( ClapTrap const &other );

	/* Member Functions */
		void	attack( std::string const & target );
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );

};

#endif