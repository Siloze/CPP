#include "easyfind.hpp"

template <typename T>
void showIterator( const typename T::iterator &iterator,  const T &container)
{
    if (iterator != container.end())
        std::cout << "ITERATOR VALUE : " << *iterator << std::endl;
    else
        std::cout << "END OF THE CONTAINER REACHED" << std::endl;
}

int main(void)
{
    std::list<int> tab;
    std::list<int>::iterator iterator;

    tab.push_back(4);
    tab.push_back(49);
    tab.push_back(389);
    iterator = easyfind(tab,389);
    showIterator(iterator, tab);
    iterator = easyfind(tab,2);
    showIterator(iterator, tab);
    return (0);
}