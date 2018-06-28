#ifndef EASYFIND_HPP
# define EASYFIND_HPP
#include <iterator>
#include <iostream>
#include <vector>

template <typename T>
bool	easyfind(T & c, int element)
{
	typename T::iterator it;
	for (it = c.begin(); it != c.cend(); ++it) {
		if (*it == element) {
			return true;
		}
	}
	throw std::range_error("Not found!");
	return false;
}

#endif