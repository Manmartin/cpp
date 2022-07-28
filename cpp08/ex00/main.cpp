#include <easyfind.hpp>
#include <iostream>
#include <vector>

int main(void) {
    std::vector<int> v1(5, 10);
    std::vector<int>::iterator it;
    if ( (it = easyfind(v1, 5)) != v1.end()) 
        std::cout << *it <<"\n";
    else
        std::cout << "No esta\n";
    
 if ((it = easyfind(v1, 10)) != v1.end()) 
        std::cout << *it <<"\n";
    else
        std::cout << "No esta\n";
    return 0;
}
