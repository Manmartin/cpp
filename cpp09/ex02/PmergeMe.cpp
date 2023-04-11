#include <iostream>
#include <cstdlib>

#include "PmergeMe.hpp"

/* Constructor and Destructor */

PmergeMe::PmergeMe() { 
    this->kVec = 42;
    this->kList = 42;
}

PmergeMe::PmergeMe( PmergeMe const &ref ) { *this = ref; }
PmergeMe::~PmergeMe() {}

/* Operator */

PmergeMe    &PmergeMe::operator=( PmergeMe const &ref ) {
    this->vec = ref.vec;
    this->list = ref.list;
    this->kVec = ref.kVec;
    this->kList = ref.kList;
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
    vit it = v.begin();
    vit end = --v.end();
    for (; it != end; it++) {
        std::cout << *it << ' ';
    }
    std::cout << *it << '\n';
}

void    PmergeMe::printNumbers( lst &l ) {
    lit it = l.begin();
    lit end = --l.end();
    for (; it != end; it++) {
        std::cout << *it << ' ';
    }
    std::cout << *it << '\n';
}
