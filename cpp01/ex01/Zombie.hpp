#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <sstream>

class Zombie {
	private:

	std::string	_name;
	public:

	Zombie(void);
	~Zombie( void );

	void	announce( void );
	void	setName(std::string name);
	
};

#endif
