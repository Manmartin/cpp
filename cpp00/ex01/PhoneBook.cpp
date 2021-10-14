#include "agenda.hpp"

void	PhoneBook::add_user(void) {
	std::cout << "Please, introduce new contact's information:" << std::endl;
	_contacts[next++ % 8].set_values();
}

void	PhoneBook::search_user(void) const{
	std::string	index;
	int			n_index;

	if (next > 0)
	{
		std::cout << std::setw(10) << "Index" << "|";
		std::cout << std::setw(10) << "First Name" << "|";
		std::cout << std::setw(10) << "Last Name" << "|";
		std::cout << std::setw(10) << "Nickname" << std::endl;
		for (int i = 0; i < (next > 8 ? 8 : next); i++)
			_contacts[i].array_print(i);
		std::cout << "Select one of the indexes: ";
		getline(std::cin, index);
		if (std::istringstream(index) >> n_index && n_index < 8 && n_index < next)
			_contacts[n_index].self_print();
		else if (!std::cin.eof())
			std::cout << "Wrong index, try \"SEARCH\" again" << std::endl;
	}
	else
		std::cout << "There are no contacts yet" << std::endl;
}
