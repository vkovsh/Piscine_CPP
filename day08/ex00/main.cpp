#include "easyfind.hpp"
#include <vector>
#include <list>
#include <exception>

template <typename T>
bool	easyfind(T & c, int element);

int	main(void)
{
	try {
		std::vector<int> second(4,100);
		std::list<int> first;
		for (int i = 0; i < 10; ++i) {
			first.push_back(rand() % 255);
		}
		std::cout << easyfind(second, 100) << std::endl;
		std::cout << easyfind(second, 100) << std::endl;
		std::cout << easyfind(first, 4) << std::endl;
		std::cout << easyfind(first, 101) << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}