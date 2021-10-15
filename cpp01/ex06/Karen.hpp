#ifndef KAREN_HPP
# define KAREN_HPP

# include <iostream>
# include <string>
# include <sstream>

class Karen {
	private:
	static	void	base( void );
	static	void	debug( void );
	static	void	info( void );
	static	void	warning( void );
	static	void	error( void );

	void	(*_functions[5])(void);

	public:
	Karen(void);
	~Karen(void);
	void	complain( std::string level );
};

#endif