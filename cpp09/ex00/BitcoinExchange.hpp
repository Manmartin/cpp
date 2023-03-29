#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <vector>
# include <stdlib.h>

class BitcoinExchange
{
    private:
        typedef struct s_data {
            unsigned int date;
            float       value;
        } t_data ;

        std::vector<t_data> _dbLines;
        std::vector<std::string> _inputLines;

        unsigned int readDate( const std::string source );
        float   searchDate( const float date, unsigned low, unsigned high );
        bool    parseNumber( float *n, const char *str );

    public:
        BitcoinExchange();
        BitcoinExchange( BitcoinExchange const &ref );
        ~BitcoinExchange();

        BitcoinExchange &operator=( BitcoinExchange const &ref );

        bool    loadFile( const char *const fileName );
        void    printValues( void );
};

#endif
