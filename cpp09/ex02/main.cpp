#include <iostream>
#include <unistd.h>

#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Error\n";
        return 1;
    }

    int i = 1;
    PmergeMe sort;
    if (argv[1] == std::string("--optimize")) {
        sort.getK();
        i = 2;
    }

    for (; i < argc; i++) {
        if (!sort.addNumber(argv[i])) {
            std::cout << "Error\n";
            return 1;
        }
    }
    sort.makeBenchmark();
    return 0;
}
