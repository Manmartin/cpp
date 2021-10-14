#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "agenda.hpp" 

class Contact {

	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;

		std::string	_format_string(std::string s) const;
	public:
		void		set_values(void);
		void		array_print(int) const;
		void		self_print(void) const;
};

#endif