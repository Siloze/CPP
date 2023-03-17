#pragma once

#include "BitcoinExchange.hpp"

class Date
{
    public:
    	Date(std::string timestamp);
    	~Date();
		bool operator>(Date &other);
		bool operator<(Date &other);
		bool operator==(Date &other);
		bool operator!=(Date &other);
		bool operator<=(Date &other);
		bool operator>=(Date &other);
		int	operator-(Date &other);
		int year;
		int mounth;
		int day;

};

std::ostream& operator<<(std::ostream& os, const Date& dt);