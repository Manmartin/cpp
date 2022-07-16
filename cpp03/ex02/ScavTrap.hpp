#ifndef SCAVTRAP_HPP 
# define SCAVTRAP_HPP

#include <ClapTrap.hpp>
#include <iostream>
#include <string>

class ScavTrap: public ClapTrap {
	public:
		ScavTrap( void );
		ScavTrap( ScavTrap const &ref );
		ScavTrap( std::string const &name );
		~ScavTrap( void );

		ScavTrap	&operator=( ScavTrap const &ref );

		void	attack( std::string const &target ) const;
		void	guardGate( void );	
};

#endif
