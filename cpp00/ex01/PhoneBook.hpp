#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "agenda.hpp"

class PhoneBook
{
	private:
		Contact _contacts[8];
	public:
		int		next;
		void	add_user(void);
		void	search_user(void) const;
};

#endif