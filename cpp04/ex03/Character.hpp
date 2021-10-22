#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "includes.hpp"

class ICharacter {

    public:

        virtual ~ICharacter() {}
        virtual std::string const & getName() const = 0;
        virtual void equip( AMateria * m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};

class Character: public ICharacter {
    private:
        Character( void );
        std::string     _name;
        AMateria        *_inventory[4];

    public:
        Character( std::string name );
        Character(Character const &other);
        ~Character();

        Character const &operator=(Character const &other);

        std::string const   &getName( void ) const;
        void equip( AMateria* m );
        void unequip( int idx );
        void use( int idx, ICharacter& target );

};

#endif