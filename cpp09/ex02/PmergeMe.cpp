#include <iostream>
#include <cstdlib>

#include "PmergeMe.hpp"

/* Constructor and Destructor */

PmergeMe::PmergeMe() { this->k = 42; }
PmergeMe::PmergeMe( PmergeMe const &ref ) { *this = ref; }
PmergeMe::~PmergeMe() {}

/* Operator */

PmergeMe    &PmergeMe::operator=( PmergeMe const &ref ) {
    this->vec = ref.vec;
    this->list = ref.list;
    return *this;
}

/* Aux */

bool    PmergeMe::addNumber( const char *numberStr ) {
    int64_t n;
    char *err;
    n = std::strtol(numberStr, &err, 10);
    if ( n < 0 || n > INT32_MAX || numberStr == err || *err != '\0' )
        return false;
    vec.push_back(n);
    list.push_back(n);
    return true;
}

void    PmergeMe::printNumbers( vector &v ) {
    std::vector<int32_t>::iterator it = v.begin();
    std::vector<int32_t>::iterator end = --v.end();
    for (; it != end; it++) {
        std::cout << *it << ' ';
    }
    std::cout << *it << '\n';
}
