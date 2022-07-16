#ifndef FragTrap_HPP 
# define FragTrap_HPP

#include <ClapTrap.hpp>
#include <iostream>
#include <string>

class FragTrap: public ClapTrap {
	public:
		FragTrap( void );
		FragTrap( FragTrap const &ref );
		FragTrap( std::string const &name );
		~FragTrap( void );

		FragTrap	&operator=( FragTrap const &ref );

		void	attack( std::string const &target ) const;
		void	highFivesGuys( void );
};

#endif
