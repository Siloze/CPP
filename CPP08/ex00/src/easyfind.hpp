# ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <list>
# include <vector>

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator search = find(container.begin(), container.end(), value);
	if (search == container.end())
		return (container.end());
	return (search);
}
# endif