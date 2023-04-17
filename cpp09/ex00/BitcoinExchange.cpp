#include <iostream>
#include <fstream>
#include <cstdlib>

#include "BitcoinExchange.hpp"

/* Constructors and Destructor */
BitcoinExchange::BitcoinExchange () {}
BitcoinExchange::BitcoinExchange( BitcoinExchange const &ref ) { *this = ref; }
BitcoinExchange::~BitcoinExchange () { this->inputFile.close(); }

/* Operators */

BitcoinExchange &BitcoinExchange::operator=( BitcoinExchange const &ref ) { 
    this->database = ref.database;
    return *this;
}

/* File reading */

bool    BitcoinExchange::loadDatabase( void ) {
    std::ifstream file("data.csv");
    if (!file.is_open()) {
        std::cout << "Error: could not open database\n";
        return false;
    }

    std::string line;
    uint32_t date;
    float value;
    std::getline(file, line); /* Remove database header */
    while (std::getline(file, line)) {
        if (!parseDate(&date, line) || !parseNumber(&value, &line[11])) {
            std::cout << "Error: bad database format\n";
            file.close();
            return false;
        }
        this->database.insert(databasePair(date, value));
    }
    file.close();
    return true;
}

bool    BitcoinExchange::loadInput( const char *const filename ) {
    this->inputFile.open(filename);
    if (!this->inputFile.is_open()) {
        std::cout << "Error: could not open file.\n";
        return false;
    }
    return true;
}

/* Show result */

void    BitcoinExchange::printValues( void ) {
    std::string line;
    uint32_t date;
    float value;

    std::getline(inputFile, line); /* Remove input header */
    while(std::getline(inputFile, line)) {
        if (!parseDate(&date, line))
            std::cout << "Error: bad input => '" << line << "'\n";
        else if (line[10] != ' ' || line[11] != '|' || line[12] != ' ') 
            std::cout << "Error: bad input => '" << line << "'\n";
        else if (!parseNumber(&value, &line[13]))
            std::cout << "Error: bad input => '" << line << "'\n";
        else if (value < 0)
            std::cout << "Error: not a positive number.\n";
        else if (value > 1000)
            std::cout << "Error: too large a number.\n";
        else {
            std::cout << line.substr(0, 11)
            << " => " << value
            << " = " << searchDate(date) * value
            << '\n';
        }
    }
}

/* Parse functions */

bool BitcoinExchange::checkDate( uint32_t year, uint32_t month, uint32_t day ) {
    bool leap = year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
    if (year < 1582) /* Year in which the Gregorian calendar comes into use */
        return false;
    else if (month < 1 || month > 12) /* Month range*/
        return false;
    else if (day < 1 || day > 31) /* Day range */
        return false;
    else if (month == 2 && day == 29 && !leap) /* Check leap years */
        return false;
    else if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11)) /* Check 30-day month */
        return false;
    return true;
}

bool BitcoinExchange::parseDate( uint32_t *date, const std::string source ) {
    uint32_t year = 0 , month = 0, day = 0;
    /* Year */
    for (int i = 0; i < 4; i++) {
        if (!isdigit(source[i]))
            return false;
        year = year * 10 + source[i] - '0';
    }
    if (isdigit(source[4] != '-'))
        return false;
    /* Month */
    for (int i = 5; i < 7; i++) {
        if (!isdigit(source[i]))
            return false;
        month =  month * 10 + source[i] - '0';
    }
    /* Day */
    if (isdigit(source[7] != '-'))
        return false;
    for (int i = 8; i < 10; i++) {
        if (!isdigit(source[i]))
            return false;
        day = day * 10 + source[i] - '0';
    }
    *date = year * 10000 + month * 100 + day;
    return checkDate(year, month, day);
}

bool    BitcoinExchange::parseNumber( float *n, const char *str ) {
        char *err;
        *n = strtof(str, &err);
        if (*err != '\0' || str == err)
            return false;
        return true;
}

/* Algorithm */

float    BitcoinExchange::searchDate( const uint32_t &date ) {
    databaseMap::iterator databaseDate = database.lower_bound(date);
    if (date <= database.begin()->first)
        return database.begin()->second;
    return databaseDate->first == date ? databaseDate->second : (--databaseDate)->second;
}
