#include <iostream>
#include <fstream>

std::string replace(std::string line, std::string search, std::string replace)
{
	int i = -1;

	while (++i < line.length())
	{
		if (line[i] == search[0])
		{
			if (!line.compare(i, search.length(), search))
			{
				line.erase(i, search.length());
				line.insert(i, replace);
				i += replace.length();
			}
		}
	}
	return (line);
}
int main(int ac, char **av)
{
	std::string line;
	std::fstream file;
	std::fstream file_replace;

	if (ac != 4)
		return (printf("Wrong args\n"));
	line.operator=(av[1]);
	file.open(line);
	if (!file.is_open())
		return (printf("Wrong args\n"));
	line.operator+=(".replace");
	file_replace.open(line, std::ios::out);
	if (!file_replace.is_open())
	{
		file.close();
		return (printf("Wrong args\n"));
	}
	while (std::getline(file, line))
	{
		line = replace(line, av[2], av[3]);
		file_replace << line << std::endl;
	}
	file.close();
	file_replace.close();
	return (0);
}