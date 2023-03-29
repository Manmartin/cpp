#include "RPN.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Error\n";
        return 1;
    }
    RPN r;
    if (!r.readExpression(argv[1])) {
        std::cout << "Error\n";
        return 1;
    }
    return 0;
}
