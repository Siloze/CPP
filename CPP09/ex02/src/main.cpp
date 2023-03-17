#include "PmergeMe.hpp"

template <class TCONTAINER>
int getTimeOfProcess(TCONTAINER &a)
{
	clock_t start = clock();
	a = sortmerge(a);
	clock_t end = clock();
	return (end - start);
}

template <class TCONTAINER>
void printContainer(TCONTAINER &a, std::string msg = "")
{
	if (msg != "")
		std::cout << msg << std::endl;
	for (typename TCONTAINER::iterator it = a.begin(); it != a.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void launchProcess(CONTAINER1 &a, CONTAINER2 &b)
{
	printContainer(a, "Before sort:");
	double time1 = getTimeOfProcess(a);
	double time2 = getTimeOfProcess(b);
	printContainer(a, "After sort:");
	std::cout << "Time of deque for "<< a.size() << " elements: " << time1 << " ticks" << std::endl;
	std::cout << "Time of list for "<< b.size() << " elements: " << time2 << " ticks" << std::endl;
}

int main (int ac, char **av)
{
	CONTAINER1 a;
	CONTAINER2 b;

	if (ac < 2)
		return 0;
	for (int i = 1; i < ac; i++)
	{
		if (is_interger(av[i]))
		{
			a.push_back(atoi(av[i]));
			b.push_back(atoi(av[i]));
		}
		else
		{
			std::cout << "Error: " << av[i] << " is not a valid positve integer." << std::endl;
			return 0;
		}
	}
	if (a.size() > 1)
	{
		launchProcess(a, b);
	}
	else
		std::cout << "Error: too small array." << std::endl;
	return 0;
}