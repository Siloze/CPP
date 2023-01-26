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
		throw std::runtime_error("Can't find occurence");
	return (search);
}
# endif