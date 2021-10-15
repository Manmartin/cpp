#include "Karen.hpp"
# include <string.h>
# include <stdio.h>

int main (int argc, char *argv[]) {
    Karen       karen;
    std::string str;
    if (argc == 2)
    {
        str = std::string(argv[1]);
        if ( !(!str.compare("DEBUG") | !str.compare("INFO") | !str.compare("WARNING") | !str.compare("ERROR")) )
        {
            karen.complain("0");
            return (0);
        }
        switch (argv[1][0]) {
            default:
                karen.complain("0");
                break;
            case  'D': {
                std::cout << "[ DEBUG ]" << std::endl;
                karen.complain("1");
                std::cout << std::endl;
            }
            case  'I': {
                std::cout << "[ INFO ]" << std::endl;
                karen.complain("2");
                std::cout << std::endl;

            }
            case  'W': {
                std::cout << "[ WARNING ]" << std::endl;
                karen.complain("3");
                std::cout << std::endl;
            }
            case  'E': {
                std::cout << "[ ERROR ]" << std::endl;
                karen.complain("4");
                std::cout << std::endl;
            }
        }
    }
    else
        karen.complain("0");
    return(0);
}
