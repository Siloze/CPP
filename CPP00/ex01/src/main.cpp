#include "Contact.hpp"
#include <iostream>
#include <string.h>

void add_contact(Contact *file)
{
	std::string str;

	std::cout << "----------------------" << std::endl;
	std::cout << "      NEW CONTACT" << std::endl;
	std::cout << "----------------------" << std::endl;
	while (str.empty() || !file->setFirstName(str))
	{
		std::cout << "First Name : " << std::endl;
		std::getline(std::cin, str);
		std::cout << "STR : '" << str  << "'" << std::endl;
	}
	str.clear();
	while (str.empty() || !file->setLastName(str))
	{
		std::cout << "Last Name : " << std::endl;
		std::getline(std::cin, str);
	}
	str.clear();
	while (str.empty() || !file->setNickName(str))
	{
		std::cout << "Nick Name : " << std::endl;
		std::getline(std::cin, str);
	}
	str.clear();
	while (str.empty() || !file->setPhoneNumber(str))
	{
		std::cout << "Phone Number : " << std::endl;
		std::getline(std::cin, str);
	}
	str.clear();
	while (str.empty() || !file->setDarkestSecret(str))
	{
		std::cout << "Darkest secret : " << std::endl;
		std::getline(std::cin, str);
	}
	std::cout << "----------------------" << std::endl;
	std::cout << "      CONTACT ADD" << std::endl;
	std::cout << "----------------------" << std::endl;
	if (file->getNumberOf() < 8)
		file->setNumberOf(file->getNumberOf() + 1);
	file->setSelected(file->getSelected() + 1);
}

int show_contact(Contact contact, int do_cut, int index)
{
	if (do_cut)
		std::cout << index << "         ";
	if (!do_cut)
		std::cout << std::endl;
	else
		std::cout << "|";
	std::cout << contact.getFirstName(do_cut);
	if (!do_cut)
		std::cout << std::endl;
	else
		std::cout << "|";
	std::cout << contact.getLastName(do_cut);
	if (!do_cut)
		std::cout << std::endl;
	else
		std::cout << "|";
	std::cout << contact.getNickName(do_cut);
	if (!do_cut)
		std::cout << std::endl;
	else
		std::cout << "|";
	std::cout << contact.getPhoneNumber(do_cut);
	if (!do_cut)
		std::cout << std::endl;
	else
		std::cout << "|";
	std::cout << contact.getDarkestSecret(do_cut) << std::endl;
	return (0);
}

int contact_all(Contact *book)
{
	int i;
	std::string str;

	i = -1;
	if (book->getNumberOf())
		std::cout << "  INDEX   | FIRSTNAME| LASTNAME | NICKNAME |  PHONE   | Darkest Secret" << std::endl;
	else
		return (1);
	while (++i < book->getNumberOf())
		show_contact(book[i], 1, i);
	while (str.length() != 1 || (str[0] > '8' || str[0] < '0') || str[0] - '0' >= book->getNumberOf())
	{
		std::cout << "Choose an Index > ";
		std::cin >> str;
	}
	return (show_contact(book[str[0] - '0'], 0, str[0] - '0'));
}

int main(void)
{
	Contact *book = new Contact[8];    
	std::string string;

	while (string.compare("EXIT"))
	{
		std::cout << "$> ";
		std::getline(std::cin, string);
		if (!string.compare("ADD"))
		{
			if (book->getSelected() > 7)
				book->setSelected(0);
			add_contact(&book[book->getSelected()]);
		}
		else if (!string.compare("SEARCH"))
			contact_all(book);
		else if (string.compare("EXIT"))
			std::cout << "ALL COMMANDS :\n\t- ADD\n\t- SEARCH\n\t- EXIT" << std::endl;
	}

	delete [] book;

}
