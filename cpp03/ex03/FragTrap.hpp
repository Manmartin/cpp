#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public virtual ClapTrap {
	private:

	public:
		static const unsigned int life;
		static const unsigned int energy;
		static const unsigned int damage;
	/* Constructors and destructor */

		FragTrap( void );
		FragTrap( std::string name );
		FragTrap( FragTrap const &other );
		~FragTrap( void );

	/* operators overload */

		FragTrap const &operator=( FragTrap const &other );
	
	/* member functions */
	void	highFives( void );

};

#endif