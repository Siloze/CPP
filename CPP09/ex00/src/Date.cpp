#include "Date.hpp"

Date::Date(std::string timestamp)
{
    if (!isDateValid(timestamp))
    {
        throw std::runtime_error("Error: invalid timestamp format " + timestamp + " (YYYY-MM-DD).");
    }
    year = std::stod(timestamp.substr(0, 4));
    mounth = std::stod(timestamp.substr(5, 2));
    day = std::stod(timestamp.substr(8, 2));
    if (mounth > 12 || mounth < 0 || day > 31 || day < 0 || year < 0)
        throw std::runtime_error("Error: invalid timestamp values " + timestamp + " (0-9999 0-12 0-31).");

}

Date::~Date()
{
    return ;
}

bool Date::operator<(Date &other)
{
    if (year < other.year)
        return true;
    else if (year == other.year)
    {
        if (mounth < other.mounth)
            return true;
        else if (mounth == other.mounth)
            if (day < other.day)
                return true;
    }
    return false;
}

int Date::operator-(Date &other)
{
    int resul = year - other.year + mounth - other.mounth + day - other.day;
    if (resul < 0)
        return -resul;
    return resul;
}

bool Date::operator==(Date &other)
{
    if (this->year == other.year && this->mounth == other.mounth && this->day == other.day)
        return true;
    return false;
}

bool Date::operator!=(Date &other)
{
    return !(*this == other);
}

bool Date::operator>(Date &other)
{
    return !(*this < other) && *this != other;
}

bool Date::operator<=(Date &other)
{
    return *this < other || *this == other;
}

bool Date::operator>=(Date &other)
{
    return *this > other || *this == other;
}

std::ostream& operator<<(std::ostream& os, const Date& dt)
{
    os << dt.year << '-' << dt.mounth << '-' << dt.day;
    return os;
}