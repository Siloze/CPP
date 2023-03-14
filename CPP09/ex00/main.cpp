#include <iostream>
#include <fstream>
#include <vector>

#define CONTAINER std::vector<std::pair<std::string, std::string> >

std::string getDate(std::string &line, char c)
{
    return line.substr(0, line.find(c));
}

std::string getValue(std::string &line, char c)
{
    return line.substr(line.find(c) + 1);
}

CONTAINER initData(std::string DatabasePath)
{
    std::fstream database;
    CONTAINER values;
    std::string line;
    database.open(DatabasePath);
    while (database)
    {
        std::getline(database, line);
        values.push_back(std::make_pair(getDate(line, ','), getValue(line, ',')));
    }
    return values;
}

bool isDateValid(std::string &date)
{
    return true;
}

bool isValueValid(std::string &date)
{
    return true;
}

void parseDate(std::string &date, std::string &year, std::string &mouth, std::string &day)
{
    year = date.substr(0, 4);
    mouth = date.substr(5, 9);
    day = date.substr(10, 14);
    return ;
}
double getValueByDate(std::string &date, CONTAINER &data)
{
    std::string year;
    std::string mouth;
    std::string day;

    for(int i = 0; i != data.size(); i++)
    {
        parseDate(date, year, mouth, day);
        
    }
    //std::cout << "check data: " << date << std::endl;
    return 1;
}

void processInput(std::string date, std::string value, CONTAINER &data)
{
    double result;
    if (isDateValid(date))
    {
        if (isValueValid(value))
        {
            result = getValueByDate(date, data) * std::stod(value);
            std::cout << date << " => " << std::stod(value) << " = " << result << std::endl;
        }
        else
            std::cout << "Invalid value: " << value << std::endl;
    }
    else
        std::cout << "Invalid AAAA-MM-JJ data: " << date << std::endl;
}

int main(int ac, char **av)
{
    CONTAINER data = initData("data.csv");
    std::fstream userFile;
    std::string line;
    userFile.open(av[1]);
    while (userFile)
    {
        std::getline(userFile, line);
        if (line.length() > 1)
            processInput(getDate(line, '|'), getValue(line, '|'), data);
    }
    return 0;
}