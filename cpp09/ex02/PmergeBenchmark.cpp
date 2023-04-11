#include <iostream>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <sys/time.h>

#include "PmergeMe.hpp"

double PmergeMe::BenchmarkVec( void ) {
    uint32_t right = vec.size() - 1;
    struct timeval begin, end;

    gettimeofday(&begin, 0);
    mergeInsertionSortVec(vec, 0, right);
    gettimeofday(&end, 0);

    double seconds = end.tv_sec - begin.tv_sec;
    double microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds*1e-6;
    return elapsed;
}

double PmergeMe::BenchmarkList( void ) {
    uint32_t right = list.size() - 1;
    struct timeval begin, end;

    gettimeofday(&begin, 0);
    mergeInsertionSortList(list, 0, right);
    gettimeofday(&end, 0);

    double seconds = end.tv_sec - begin.tv_sec;
    double microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds*1e-6;
    return elapsed;
}

void    PmergeMe::makeBenchmark( void ) {
    double vecTime, listTime;
    std::cout << std::left;
    std::cout << std::setw(9) << "before:";
    this->printNumbers(vec);

    vecTime = this->BenchmarkVec();
    listTime = this->BenchmarkList();


    std::cout << std::setw(9) << "after:";
    this->printNumbers(list);

    std::cout << std::right;
    std::cout << "Time to process a range of " << std::setw(4) << vec.size() 
    << " elements with std::vector : " << std::fixed << std::setprecision(6) << vecTime << " s\n";
    std::cout << "Time to process a range of " << std::setw(4) << list.size()
    << " elements with std::list   : " << std::fixed << std::setprecision(6) << listTime << " s\n";
    if (vec.size() != list.size() || !std::equal(vec.begin(), vec.end(), list.begin()))
        std::cout << "Error: Containers not equal\n";
}
