#include <easyfind.hpp>
#include <iostream>
#include <vector>
#include <list>
#include <deque>


#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

int main(void) {
    {
        std::cout << BLUE << "Int vector\n\n";
        std::vector<int> v1(5, 10);
        if ( easyfind(v1, 5) != v1.end()) 
            std::cout << GREEN << *easyfind(v1, 5) <<"\n";
        else
            std::cout << YELLOW << "didn't find it\n";
        std::cout << RESET;
        if ((easyfind(v1, 10)) != v1.end()) 
            std::cout << GREEN << *easyfind(v1, 10) <<"\n";
        else
            std::cout << YELLOW << "didn't find it\n";
        std::cout << RESET;
    }
    std::cout << '\n';
    {
        std::cout << BLUE << "Int vector empty\n\n";
        std::vector<int> v1;
        if ( easyfind(v1, 5) != v1.end()) 
            std::cout << GREEN << *easyfind(v1, 5) <<"\n";
        else
            std::cout << YELLOW << "didn't find it\n";
        std::cout << RESET;
        if ((easyfind(v1, 10)) != v1.end()) 
            std::cout << GREEN << *easyfind(v1, 10) <<"\n";
        else
            std::cout << YELLOW << "didn't find it\n";
        std::cout << RESET;
    }
    
    std::cout << '\n';
    {
        std::cout << BLUE << "Int list\n\n";
        std::list<int> v1(2, 5);
        if ( easyfind(v1, 5) != v1.end()) 
            std::cout << GREEN << *easyfind(v1, 5) <<"\n";
        else
            std::cout << YELLOW << "didn't find it\n";
        std::cout << RESET;
        if ((easyfind(v1, 10)) != v1.end()) 
            std::cout << GREEN << *easyfind(v1, 10) <<"\n";
        else
            std::cout << YELLOW << "didn't find it\n";
        std::cout << RESET;
    }
        std::cout << '\n';
    {
        std::cout << BLUE << "Int list empty\n\n";
        std::list<int> v1;
        if ( easyfind(v1, 5) != v1.end()) 
            std::cout << GREEN << *easyfind(v1, 5) <<"\n";
        else
            std::cout << YELLOW << "didn't find it\n";
        std::cout << RESET;
        if ((easyfind(v1, 10)) != v1.end()) 
            std::cout << GREEN << *easyfind(v1, 10) <<"\n";
        else
            std::cout << YELLOW << "didn't find it\n";
        std::cout << RESET;
    }
    std::cout << '\n';
    {
        std::cout << BLUE << "Int deque\n\n";
        std::deque<int> v1(10, 7);
        if (easyfind(v1, 5) != v1.end()) 
            std::cout << GREEN << *easyfind(v1, 5) <<"\n";
        else
            std::cout << YELLOW << "didn't find it\n";
        std::cout << RESET;
        if ((easyfind(v1, 7)) != v1.end()) 
            std::cout << GREEN << *easyfind(v1, 7) <<"\n";
        else
            std::cout << YELLOW << "didn't find it\n";
        std::cout << RESET;
    }
        std::cout << '\n';
    {
        std::cout << BLUE << "Int deque empty\n\n";
        std::deque<int> v1;
        if ( easyfind(v1, 5) != v1.end()) 
            std::cout << GREEN << *easyfind(v1, 5) <<"\n";
        else
            std::cout << YELLOW << "didn't find it\n";
        std::cout << RESET;
        if ((easyfind(v1, 10)) != v1.end()) 
            std::cout << GREEN << *easyfind(v1, 10) << "\n";
        else
            std::cout << YELLOW << "didn't find it\n";
        std::cout << RESET;
    }
    return 0;
}
