#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
	
	protected:
		std::string		_name;
		unsigned int	_hitpoints;
		unsigned int	_energy;
		unsigned int	_attack;

	public:
		ClapTrap( void );
		ClapTrap( ClapTrap const &ref );
		ClapTrap( std::string const &name );
		~ClapTrap( void );

		ClapTrap	&operator=( ClapTrap const &ref );

		void	attack( std::string const &target ) const;
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );
};

#endif
