#include "includes.hpp"

bool isDateValid(std::string &date)
{
    while(date.at(date.size() - 1) == ' ')
        date.erase(date.size() - 1);
    if (date.size() != 10)
        return false;
    for(int i = 0; i != date.size(); i++)
    {
        if (i != 4 && i != 7 && i != 10)
        {
            if (date.at(i) < '0' || date.at(i) > '9')
                return false;
        }
        else if (date.at(i) != '-' && date.at(i) != '/' && date.at(i) != '|')
            return false;
    }
    return true;
}