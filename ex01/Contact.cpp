#include "Contact.hpp"
#include <string.h>
#include <iostream>

Contact::Contact (void) :
firstname(""),
lastname(""),
nickname(""),
phoneNb("")
{
    return ;
}

Contact::~Contact (void)
{
    return ;
}

std::string Contact::getFirstName(void) const
{
    return (this->firstname);
}
std::string Contact::getLastName(void) const
{
    return (this->lastname);
}
std::string Contact::getNickName(void) const
{
    return (this->nickname);
}
std::string Contact::getPhoneNumber(void) const
{
    return (this->phoneNb);
}

int Contact::setFirstName(std::string first)
{
    int i;

    i = -1;
    while(first[++i])
    {
        if (first[i] != ' ' && first[i] != '\n')
        {
            this->firstname = first;
            return (1);
        }
    }
    return (0);
}
int Contact::setLastName(std::string last)
{
    int i;

    i = -1;
    while(last[++i])
    {
        if (last[i] != ' ' && last[i] != '\n')
        {
            this->lastname = last;
            return (1);
        }
    }
    return (0);
}
int Contact::setNickName(std::string nick)
{
    int i;

    i = -1;
    while(nick[++i])
    {
        if (nick[i] != ' ' && nick[i] != '\n')
        {
            this->nickname = nick;
            return (1);
        }
    }
    return (0);
}
int Contact::setPhoneNumber(std::string phone)
{
    int i;

    i = -1;
    while(phone[++i])
    {
        if (phone[i] > '9' || phone[i] < '0')
            return (0);
    }
    this->phoneNb = phone;
    return (1);
}
