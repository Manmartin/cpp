#include <mutantstack.hpp>
#include <iostream>
#include <algorithm>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"


int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
 
    std::cout << BLUE << "Deep copy test with '=' operator\n" << RESET;
    std::cout << YELLOW << " * original = 5 3 5 737 0 *\n\n" << RESET;
    {
        MutantStack<int> copy = mstack;
        copy.push(42);
        MutantStack<int>::iterator it = copy.begin();
        MutantStack<int>::iterator ite = copy.end();
        std::cout << "Copy =";
        while (it != ite)
        {
            std::cout << ' ' << *it;
            ++it;
        }
    }
    std::cout << '\n';
    std::cout << "Original =";
    it = mstack.begin();
    ite = mstack.end();
    while (it != ite) {
        std::cout << ' ' << *it;
        ++it;
    }
    std::cout << "\n\n";

    std::cout << BLUE << "Deep copy test with copy constructor\n" << RESET;
    std::cout << YELLOW << " * original = 5 3 5 737 0 *\n\n" << RESET;
    {
        MutantStack<int> copy(mstack);
        copy.push(42);
        MutantStack<int>::iterator it = copy.begin();
        MutantStack<int>::iterator ite = copy.end();
        std::cout << "Copy =";
        while (it != ite)
        {
            std::cout << ' ' << *it;
            ++it;
        }
    }
    std::cout << '\n';
    std::cout << "Original =";
    it = mstack.begin();
    ite = mstack.end();
    while (it != ite) {
        std::cout << ' ' << *it;
        ++it;
    }
    std::cout << "\n\n";

    std::cout << BLUE << "Using find with mstack\n" << RESET;
    std::cout << YELLOW << " * mstack = 5 3 5 737 0 *\n\n" << RESET;
    std::cout << YELLOW << " * find(737) *\n" << RESET;
    it = mstack.begin();
    ite = mstack.end();
    if (find(it, ite, 737) != ite)
        std::cout << "find it\n";
    else
        std::cout << "didn't find it\n";
    std::cout << YELLOW << " * find(543) *\n" << RESET;
    if (find(it, ite, 543) != ite)
        std::cout << "find it\n";
    else
        std::cout << "didn't find it\n";
    std::cout << '\n';

    
    std::cout << BLUE << "Applying a function to each element (* 2)\n" << RESET;
    it = mstack.begin();
    ite = mstack.end();
    std::cout << "new_mstack =";
    while (it != ite) {
        *it *= 2;
        std::cout << ' ' << *it;
        ++it;
    }
    std::cout << "\n\n";

    return 0;
}
