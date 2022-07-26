#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class Data {
	private:
		int nb;
		float nbf;
		double nbd;

	public:
		Data();
		Data( Data const &ref );
		Data( int nb, float nbf, double nbd );
		~Data();
		
		Data &operator=( Data const &ref );
		void	printData( void );
};

#endif
