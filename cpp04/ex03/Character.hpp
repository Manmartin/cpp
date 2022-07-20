#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <AMateria.hpp>

class Character: public ICharacter {
	private:
		std::string	name;
		AMateria	*inventory[4];
	public:
		Character( std::string const &name );
		Character( Character const &ref );
		Character( void );
		~Character();

		Character const &operator=( Character const &ref );
		
		std::string const & getName( void ) const;
		void equip( AMateria* m );
		void unequip( int idx );
		void use( int idx, ICharacter& target );

};

#endif
