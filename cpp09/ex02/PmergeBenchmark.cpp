#include <iostream>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <sys/time.h>

#include "PmergeMe.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

double PmergeMe::tryInsertion( vector &v, int32_t right ) {
    struct timeval begin, end;

    gettimeofday(&begin, 0);
    insertionSortVec(v, 0, right);
    gettimeofday(&end, 0);

    uint64_t seconds = end.tv_sec - begin.tv_sec;
    uint64_t microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds*1e-6;
    return elapsed;
}

double PmergeMe::tryMerge( vector &v, int32_t right ) {
    struct timeval begin, end;

    gettimeofday(&begin, 0);
    mergeSortVec(v, 0, right);
    gettimeofday(&end, 0);

    uint64_t seconds = end.tv_sec - begin.tv_sec;
    uint64_t microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds*1e-6;
    return elapsed;
}

void    PmergeMe::getK( void ) {
    uint32_t const n = 500;
    std::cout << YELLOW << "Generating vectors of size " << n << "...\n\n" << RESET;

    vector original(n);
    std::srand(unsigned(std::time(NULL)));
    std::generate(original.begin(), original.end(), std::rand);
    
    vector v1, v2, aux;
    double v1Time, v2Time;

    int bestK = 0;
    int timesInARow = 0;
    int timesMergeBestThanMI;
    std::cout << YELLOW << "Starting benchmark...\n" << RESET;
    for (uint32_t i = 2; i <= n; i++) {
        timesMergeBestThanMI = 0;
        v1Time = 0;
        v2Time = 0;
        aux.resize(i + 1);
        std::copy(original.begin(), original.begin() + i + 1, aux.begin());
        this->k = i;
        for (uint32_t j = 1; j <= 1000; j++) {
            v1 = aux;
            v2 = aux;
            v1Time = tryInsertion(v1, i);
            v2Time = tryMerge(v2, i);
            timesMergeBestThanMI += v1Time / v2Time > 1.1 ? 1 : 0;
        }
        if (timesMergeBestThanMI >= 800) {
            timesInARow += 1;
        } else
            timesInARow -= timesInARow == 0 ? 0 : 1;
        if (timesInARow == 10) {
            bestK = i;
            break;
        }
    }
    this->k = bestK / 10 * 10;
    std::cout << BLUE << "Benchmark ended\n\n" << RESET;
    if (bestK == 0)
        std::cout << RED << "Merge is non optimal\n" << RESET;
    else
        std::cout << GREEN << "The most optimal K-value = " << this->k << "\n" << RESET;
}

double PmergeMe::BenchmarkVec( void ) {
    uint32_t right = vec.size() - 1;
    struct timeval begin, end;

    gettimeofday(&begin, 0);
    mergeInsertionSortVec(vec, 0, right);
    gettimeofday(&end, 0);

    uint64_t seconds = end.tv_sec - begin.tv_sec;
    uint64_t microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds*1e-6;
    return elapsed;
}

void    PmergeMe::makeBenchmark( void ) {
    double vecTime;
    std::cout << std::left;
    std::cout << std::setw(9) << "before:";
    this->printNumbers(vec);

    vecTime = this->BenchmarkVec();
    std::cout << std::setw(9) << "after:";
    this->printNumbers(vec);

    std::cout << std::right;
    std::cout << "Time to process a range of " << std::setw(4) << vec.size() 
    << " elements with std::vector : " << std::fixed << std::setprecision(6) << vecTime << " s\n";
    std::cout << "Time to process a range of " << std::setw(4) << list.size()
    << " elements with std::list   : " << vecTime << " s\n";
}
