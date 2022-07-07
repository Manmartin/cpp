#include <Karen.hpp>

int main (int argc, char **argv) {
    Karen       karen;
    std::string str;
    char        c;

    c = argc != 2 ? 0 : argv[1][0];
    str = 0 == c ? "" : std::string(argv[1]);
    c = str.compare("DEBUG") && str.compare("INFO") && str.compare("WARNING") && str.compare("ERROR") ? 0 : c;
    switch (c) {
        default:
            karen.complain("");
            break;
        case  'D': {
            std::cout << "[ DEBUG ]" << std::endl;
            karen.complain("DEBUG");
            std::cout << std::endl;
        }
        case  'I': {
            std::cout << "[ INFO ]" << std::endl;
            karen.complain("INFO");
            std::cout << std::endl;

        }
        case  'W': {
            std::cout << "[ WARNING ]" << std::endl;
            karen.complain("WARNING");
            std::cout << std::endl;
        }
        case  'E': {
            std::cout << "[ ERROR ]" << std::endl;
            karen.complain("ERROR");
            std::cout << std::endl;
        }
    }
}
