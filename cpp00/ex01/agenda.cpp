#include "agenda.hpp"

int main(void) {
    std::string input;
    PhoneBook   agenda;

    agenda.next = 0;
    std::cout << "Introduce \"ADD\", \"SEARCH\" or \"EXIT\"\n";
    while (!std::cin.eof())
    {
        getline(std::cin, input);
        if (input == "EXIT")
            break;
        else if (input == "ADD")
            agenda.add_user();
        else if (input == "SEARCH")
           agenda.search_user();
    }
    return (0);
}
