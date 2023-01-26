#include "Span.hpp"

int main()
{
	Span sp = Span(4);
	sp.addNumber(-32);
	sp.addNumber(-31);
	sp.addNumber(1932);
    sp.addNumber(39);
    try
    {
        sp.addNumber(283);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl << std::endl;

	Span sp2 = Span(100);
	srand(time(NULL));
	for (int i = 0; i < 100; i++)
	{
		sp2.addNumber(rand() % 100000);
	}
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;

    Span sp3 = Span(7);
    std::list<int> list;
    for (int i = 0; i < 5; i++)
    {
        list.push_back(rand() % 1000);
    }
    sp3.fillByIterator(list.begin(), list.end());
    std::cout << sp3 << std::endl;
    try
    {
        sp3.fillByIterator(list.begin(), list.end());
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
	return (0);
}