#ifndef ICE_HPP
# define ICE_HPP

# include <AMateria.hpp>

class Ice: public AMateria {
	public:
		Ice( void );
		Ice( Ice const &ref );
		~Ice();

		Ice const &operator=( Ice const &ref );

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
