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

std::string Contact::getFirstName(int cut) const
{
    int i = -1;
    std::string name;

    while (++i < 9 && i < (int)this->firstname.length())
        name.operator+=(this->firstname[i]);
    if (this->firstname.length() > name.length() + 1)
        name.operator+=('.');
    else
        name.operator+=(this->firstname[i]);
    while (++i <= 10 && this->firstname.length() <= name.length() - 1)
        name.insert(name.begin(), ' ');
    if (cut)
        return (name);
    else
        return (this->firstname);
}
std::string Contact::getLastName(int cut) const
{
    int i = -1;
    std::string name;

    while (++i < 9 && i < (int)this->lastname.length())
        name.operator+=(this->lastname[i]);
    if (this->lastname.length() > name.length() + 1)
        name.operator+=('.');
    else
        name.operator+=(this->lastname[i]);
    while (++i <= 10 && this->lastname.length() <= name.length() - 1)
        name.insert(name.begin(), ' ');

    if (cut)
        return (name);
    else
        return (this->lastname);
}
std::string Contact::getNickName(int cut) const
{
    int i = -1;
    std::string name;

    while (++i < 9 && i < (int)this->nickname.length())
        name.operator+=(this->nickname[i]);
    if (this->nickname.length() > name.length() + 1)
        name.operator+=('.');
    else
        name.operator+=(this->nickname[i]);
    while (++i <= 10 && this->nickname.length() <= name.length() - 1)
        name.insert(name.begin(), ' ');
    if (cut)
        return (name);
    else
        return (this->nickname);
}
std::string Contact::getPhoneNumber(int cut) const
{
    int i = -1;
    std::string name;

    while (++i < 9 && i < (int)this->phoneNb.length())
        name.operator+=(this->phoneNb[i]);
    if (this->phoneNb.length() > name.length() + 1)
        name.operator+=('.');
    else
        name.operator+=(this->phoneNb[i]);
    while (++i <= 10 && this->phoneNb.length() <= name.length() - 1)
        name.insert(name.begin(), ' ');
    if (cut)
        return (name);
    else
        return (this->phoneNb);
}

std::string Contact::getDarkestSecret(int cut) const
{
    int i = -1;
    std::string name;

    while (++i < 9 && i < (int)this->secret.length())
        name.operator+=(this->secret[i]);
    if (this->secret.length() > name.length() + 1)
        name.operator+=('.');
    else
        name.operator+=(this->secret[i]);
    while (++i <= 10 && this->secret.length() <= name.length() - 1)
        name.operator+=(' ');

    if (cut)
        return (name);
    else
        return (this->secret);
}

int Contact::getSelected(void) const
{
    return (this->_selected);
}

int Contact::getNumberOf(void) const
{
    return (this->_numberof);
}

int Contact::setSelected(int nb)
{
    this->_selected = nb;
    return (0);
}

int Contact::setNumberOf(int nb)
{
    this->_numberof = nb;
    return (0);
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

int Contact::setDarkestSecret(std::string secret)
{
    int i;

    i = -1;
    while(secret[++i])
    {
        if (secret[i] != ' ' && secret[i] != '\n')
        {
            this->secret = secret;
            return (1);
        }
    }
    return (0);
}

int Contact::_selected = 0;
int Contact::_numberof = 0;