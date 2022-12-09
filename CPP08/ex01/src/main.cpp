#include "Span.hpp"

int main()
{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
try
{
    Span sp2 = Span(5);
    sp2.addNumber(9);
    std::cout << sp2.shortestSpan() << std::endl;
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}

return 0;
}