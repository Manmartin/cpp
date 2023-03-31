#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <stdint.h>

class BitcoinExchange
{
    private:
        BitcoinExchange( BitcoinExchange const &ref );
        BitcoinExchange &operator=( BitcoinExchange const &ref );

        typedef std::map<uint32_t, float> databaseMap;
        typedef std::pair<uint32_t, float>  databasePair;
        databaseMap database;
        std::ifstream inputFile;

        bool    checkDate( uint32_t year, uint32_t month, uint32_t day );
        bool    parseDate( uint32_t *date, const std::string source );
        bool    parseNumber( float *n, const char *str );
    
        float   searchDate( const uint32_t &date );

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        
        bool    loadDatabase( void );
        bool    loadInput( const char *const filename );
        void    printValues( void );
};

#endif
