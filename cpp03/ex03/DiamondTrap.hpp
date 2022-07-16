#ifndef DIAMONDTRAP_HPP 
# define DIAMONDTRAP_HPP

#include <ScavTrap.hpp>
#include <FragTrap.hpp>
#include <iostream>
#include <string>

class DiamondTrap: public ScavTrap, public FragTrap {
	private:
		std::string	_name;
	public:
		DiamondTrap( void );
		DiamondTrap( DiamondTrap const &ref );
		DiamondTrap( std::string const &name );
		~DiamondTrap( void );

		DiamondTrap	&operator=( DiamondTrap const &ref );

		using	ScavTrap::attack;
		void	whoAmI( void );
};

#endif
