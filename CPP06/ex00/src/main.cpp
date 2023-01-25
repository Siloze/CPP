#include "MultiType.hpp"

int main (int ac, char **av)
{
    (void)ac;
    if (!av[1] || !is_valid(av[1]))
    {
        std::cout << "Invalid input" << std::endl;
        return 0;
    }
    if (av[1])
    {
        MultiType pd(av[1]);
        pd.showAllValue();
    }
    return 1;
}