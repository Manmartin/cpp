#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange () {
    std::ifstream file("data.csv");
    if (!file.is_open()) {
        std::cout << "Error: can't open database\n";
        exit(1);
    }

    std::string line;
    t_data data;
    std::getline(file, line);
    while (std::getline(file, line)) {
        if ((data.date = readDate(line)) == 0) {
                std::cout << "Error: bad database format.\n";
                exit(1);
        }
        else if (!parseNumber(&data.value, &(line.c_str()[11]))) {
            std::cout << "Error: bad database format.\n";
            exit(1);
        }
        //std::cout << data.date << " | " << data.value << '\n';  
        _dbLines.push_back(data);
    }
}

BitcoinExchange::BitcoinExchange( BitcoinExchange const &ref ) { *this = ref; }
BitcoinExchange::~BitcoinExchange () {}

BitcoinExchange &BitcoinExchange::operator=( BitcoinExchange const &ref ) { 
    this->_dbLines = ref._dbLines;
    this->_inputLines = ref._inputLines;
    return *this;
}


bool    BitcoinExchange::loadFile(const char *const fileName) {
    std::ifstream file(fileName);
    std::string line;

    if (!file.is_open()) {
        std::cout << "Error: could not open file.\n";
        return false;
    }

    std::getline(file, line);
    while(std::getline(file, line)) {
        _inputLines.push_back(line);
    }
    return true;
}

void    BitcoinExchange::printValues( void ) {
    t_data input;
    unsigned len = _inputLines.size();
    unsigned high = _dbLines.size() - 1;

    for (unsigned i = 0; i < len; i++) {
        if ((input.date = readDate(_inputLines[i])) == 0 )
            std::cout << "Error: bad input => '" << _inputLines[i] << "'\n";
        else if (_inputLines[i][10] != ' ' || _inputLines[i][11] != '|' || _inputLines[i][12] != ' ') 
            std::cout << "Error: bad input => '" << _inputLines[i] << "'\n";
        else if (!parseNumber(&input.value, &(_inputLines[i].c_str()[13])))
            std::cout << "Error: bad input => '" << _inputLines[i] << "'\n";
        else if (input.value < 0)
            std::cout << "Error: not a positive number.\n";
        else if (input.value > 1000)
            std::cout << "Error: too large a number.\n";
        else {
            std::cout << _inputLines[i].substr(0, 11)
            << " => " << input.value
            << " = " << searchDate(input.date, 0, high) * input.value
            << "\n";
        }
    }
}

/* Aux functions */

bool    BitcoinExchange::parseNumber(float *n, const char *str) {
        char *err;
        *n = strtof(str, &err);
        if (*err != '\0' || str == err)
            return false;
        return true;
}

unsigned int BitcoinExchange::readDate(const std::string source) {
    unsigned date = 0;
    /* Year */
    for (unsigned i = 0; i < 4; i++) {
        if (!isdigit(source[i]))
            return 0;
        date *= 10;
        date += source[i] - '0';
    }
    if (isdigit(source[4] != '-'))
        return 0;
    /* Month */
    for (unsigned i = 5; i < 7; i++) {
        if (!isdigit(source[i]))
            return 0;
        date *= 10;
        date += source[i] - '0';
    }
    /* Day */
    if (isdigit(source[7] != '-'))
        return 0;
    for (unsigned i = 8; i < 10; i++) {
        if (!isdigit(source[i]))
            return 0;
        date *= 10;
        date += source[i] - '0';
    }
    return date;
}

float   BitcoinExchange::searchDate(const float date, unsigned low, unsigned high) {
    using std::abs;
    unsigned mid;
    if (date > _dbLines[high].date)
        return _dbLines[high].value;
    else if (date < _dbLines[low].date)
        return _dbLines[low].value;

    while (true) {
        mid = (low + high) / 2;
        if (date == _dbLines[mid].date)
            return _dbLines[mid].value;
        else if (date > _dbLines[mid].date && date < _dbLines[mid + 1].date) {
            return date - _dbLines[mid].date <= _dbLines[mid + 1].date - date
            ? _dbLines[mid].value : _dbLines[mid + 1].value;
        }
        else if (date < _dbLines[mid].date && date >  _dbLines[mid - 1].date) {
            return _dbLines[mid].date - date > date - _dbLines[mid - 1].date
            ? _dbLines[mid].value : _dbLines[mid - 1].value;
        }
        else if (date > _dbLines[mid].date)
            low = mid + 1;
        else 
            high = mid - 1;
    }
}
