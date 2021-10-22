#include "Bureaucrat.hpp"


int main(void) {
    try 
    {
        std::cout << "\e[1;36m[ Wrong grade text (grade = 0) ]\e[1;0m" << std::endl;
        Bureaucrat *b = new Bureaucrat("H", 0);
        std::cout << b << std::endl;
    }
    catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    std::cout << std::endl;
    try 
    {
        std::cout << "\e[1;36m[ Wrong grade text (grade = 151) ]\e[1;0m" << std::endl;
        Bureaucrat *b = new Bureaucrat("H", 151);
        std::cout << b << std::endl;
    }
    catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    std::cout << std::endl;


    /* First Test */

    std::cout << "\e[1;36m[ Creating Bureaucrat (name = Alex, grade = 1) ]\e[1;0m" << std::endl;
    Bureaucrat *b = new Bureaucrat("Alex", 1);
    std::cout << *b << std::endl;
    std::cout << std::endl;
    try 
    {
        std::cout << "\e[1;36m[ Wrong gradeUp text (1 -> 0) ]\e[1;0m" << std::endl;
        b->gradeUp();
    }
    catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    std::cout << std::endl;
    std::cout << "\e[1;36m[ Good gradeDown text (1 -> 2) ]\e[1;0m" << std::endl;
    b->gradeDown();
    std::cout << *b << std::endl;
    delete b;


    /* Second test */

    std::cout << "\e[1;36m[ Creating Bureaucrat (name = Steve, grade = 150) ]\e[1;0m" << std::endl;
    Bureaucrat *c = new Bureaucrat("Steve", 150);
    std::cout << *c << std::endl;
    std::cout << std::endl;
    try 
    {
        std::cout << "\e[1;36m[ Wrong gradeDown text (150 -> 151) ]\e[1;0m" << std::endl;
        c->gradeDown();
    }
    catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    std::cout << std::endl;
    std::cout << "\e[1;36m[ Good gradeUp text (150 -> 149) ]\e[1;0m" << std::endl;
    c->gradeUp();
    std::cout << *c << std::endl;

    delete c;
    return 0;
}