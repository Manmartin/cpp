#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe( PmergeMe const &ref ) { *this = ref; }
PmergeMe::~PmergeMe() {}


PmergeMe    &PmergeMe::operator=( PmergeMe const &ref ) {
    return *this;    
}
