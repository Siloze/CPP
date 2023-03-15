#include "includes.hpp"

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
		try
		{
			values.push_back(std::make_pair(Date(getDate(line, ',')), getValue(line, ',')));
		}
		catch (std::exception e){
		}
	}
	return values;
}

bool isValueValid(std::string &date)
{
	double tmp;

	try
	{
		tmp = std::stod(date);
	}
	catch (std::invalid_argument e)
	{
		return false;
	}
	if (tmp > 0 && tmp <= 1000)
		return true;
	return false;
}

void parseDate(std::string &date, std::string &year, std::string &mouth, std::string &day)
{
	year = date.substr(0, 4);
	mouth = date.substr(5, 9);
	day = date.substr(10, 14);
	return ;
}

double getValueByDate(Date &date, CONTAINER &data)
{
	for (int i = 0; i < data.size(); i++)
	{

		if (date > data.at(i).first)
		{
			if (i + 1 < data.size() && date < data.at(i + 1).first)
			{
				if (!(date - data.at(i).first < date - data.at(i + 1).first))
					return std::stod(data.at(i + 1).second);
				return std::stod(data.at(i).second);
			}
		}
	}
	return -1;
}

void processInput(Date date, std::string value, CONTAINER &data)
{
	double result;
	if (isValueValid(value))
	{
	   result = getValueByDate(date, data) * std::stod(value);
	   if (result > 0)
	   		std::cout << date << " => " << std::stod(value) << " = " << result << std::endl;
		else
			std::cout << "Error: there isn't data near " << date << " yet." << std::endl;
	}
	else
		std::cout << "Error: invalid value" << value << "." << std::endl;
}

int main(int ac, char **av)
{
	CONTAINER data = initData("data.csv");
	std::fstream userFile;
	std::string line;
	userFile.open(av[1]);
	while (!userFile.eof())
	{
		std::getline(userFile, line);
		if (line.length() > 1)
		{
			try
			{
				processInput(Date(getDate(line, '|')), getValue(line, '|'), data);
			}
			catch (std::runtime_error e)
			{
				std::cout << e.what() << std::endl;
			}
		}
	}
	return 0;
}