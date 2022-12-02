#include "MultiType.hpp"

int main (int ac, char **av)
{
    if (av[1])
    {
        MultiType pd(av[1]);
        pd.showAllValue();
    }
    return 1;
}