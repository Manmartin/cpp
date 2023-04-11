#include <iostream>
#include <unistd.h>

#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Error\n";
        return 1;
    }

    PmergeMe sort;
    for (int i = 1 ; i < argc; i++) {
        if (!sort.addNumber(argv[i])) {
            std::cout << "Error\n";
            return 1;
        }
    }
    sort.makeBenchmark();
    return 0;
}
