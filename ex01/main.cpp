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
        std::cin >> str;
    }
    str.clear();
    while (str.empty() || !file->setLastName(str))
    {
        std::cout << "Last Name : " << std::endl;
        std::cin >> str;
    }
    str.clear();
    while (str.empty() || !file->setNickName(str))
    {
        std::cout << "Nick Name : " << std::endl;
        std::cin >> str;
    }
    str.clear();
    while (str.empty() || !file->setPhoneNumber(str))
    {
        std::cout << "Phone Number : " << std::endl;
        std::cin >> str;
    }
    std::cout << "----------------------" << std::endl;
    std::cout << "      CONTACT ADD" << std::endl;
    std::cout << "----------------------" << std::endl;}

void show_contact(Contact *Contact)
{
    std::cout << "FirstName : " << Contact->getFirstName() << std::endl;
    std::cout << "LastName : " << Contact->getLastName() << std::endl;
    std::cout << "NickName : " << Contact->getNickName() << std::endl;
    std::cout << "PhoneNb : " << Contact->getPhoneNumber() << std::endl;

}

int main(void)
{
    Contact *book = new Contact[8];    
    std::string string;

    while (string.compare("EXIT"))
    {
        std::cout << "$> ";
        std::cin >> string;
        if (!string.compare("ADD"))
            add_contact(book);
        else if (!string.compare("SHOW"))
            show_contact(book);
        else
            std::cout << "ALL COMMANDS :\n\t- ADD\n\t- SHOW " << std::endl;
    }

    delete [] book;

}
