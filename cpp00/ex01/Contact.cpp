#include "agenda.hpp"

void	Contact::set_values(void) {
	if (!std::cin.eof())
	{
		std::cout << "First Name: ";
		getline(std::cin, _first_name);
	}
	if (!std::cin.eof())
	{
		std::cout << "Last Name: ";
		getline(std::cin, _last_name);
	}
	if (!std::cin.eof())
	{
		std::cout << "Nickname: ";
		getline(std::cin, _nickname);
	}
	if (!std::cin.eof())
	{
		std::cout << "Phone Number: ";
		getline(std::cin, _phone_number);
	}
	if (!std::cin.eof())
	{
		std::cout << "Darkest Secret: ";
		getline(std::cin, _darkest_secret);
	}
	else
		std::cout << std::endl;
}

std::string	Contact::_format_string(std::string s) const{
	if (s.length() > 10)
		return s.substr(0, 9) + ".";
	return s;
}

void	Contact::array_print(int id) const{
	std::cout << std::setw(10) << id << "|";
	std::cout << std::setw(10) << _format_string(_first_name) << "|";
	std::cout << std::setw(10) << _format_string(_last_name) << "|";
	std::cout << std::setw(10) << _format_string(_nickname) << std::endl;
}

void	Contact::self_print(void) const{
		std::cout << "Contact's info:" << std::endl;
		std::cout << "First Name: " << _first_name << std::endl;
		std::cout << "Last Name: " << _last_name << std::endl;
		std::cout << "Nickname: " << _nickname << std::endl;
		std::cout << "Phone Number: " << _phone_number << std::endl;
		std::cout << "Darkest Secret: " << _darkest_secret << std::endl;
}
