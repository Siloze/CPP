# include <stdio.h>
# include <iostream>

template <typename Any>
void    iter(Any *tab, size_t size, void (*function)( const Any &))
{
    for (size_t i = 0; i < size; i++)
        function(tab[i]);
}

template <typename Any>
void add(Any *tab, size_t size, int nb)
{
	for (size_t i = 0; i < size; i++)
		tab[i] += nb;
}

template <typename Any>
void   print_values(Any const &value)
{
	std::cout << value << std::endl;
}
int main (void)
{
	int tab[5] = {0,1,2,3,4};
	std::cout << "INITIAL TAB : " << std::endl;
	iter<const int>(tab, 5, print_values);
	add<int>(tab, 5, 3);
	std::cout << "TAB AFTER ADDING 3" << std::endl;
	iter<const int>(tab, 5, print_values);
	std::string tab2[3] = {"salut", "a ", "toi"};
	iter<std::string>(tab2, 3, print_values);
    return (0);
}
