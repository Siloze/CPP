#include <iostream>

int main(int ac, char **argv)
{
	int i;
	int j;

	if (ac > 1)
	{
		j = 0;
		while (argv[++j])
		{
			i = -1;
			while (argv[j][++i])
			{
				if (argv[j][i] >= 'a' && argv[j][i] <= 'z')
					argv[j][i] -= 32;
				std::cout << argv[j][i];
			}
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;

}