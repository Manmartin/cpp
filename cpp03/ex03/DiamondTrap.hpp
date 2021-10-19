#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"


class DiamondTrap: public ScavTrap, public FragTrap {
	private:
		std::string	name;
	public:
	/* Constructors and destructor */

		DiamondTrap( void );
		DiamondTrap( std::string name );
		DiamondTrap( DiamondTrap const &other );
		~DiamondTrap( void );

	/* operators overload */

		DiamondTrap const &operator=( DiamondTrap const &other );
	
	/* member functions */	
		using ScavTrap::attack;
		void	whoAmI( void );

};

#endif