#include "Brain.hpp"
#include "Human.hpp"

int	main()
{
	Human bob;
	Human archi;
	
	std::cout << bob.identify() << std::endl;
	std::cout << bob.getBrain().identify() << std::endl;
	std::cout << archi.identify() << std::endl;
	std::cout << archi.getBrain().identify() << std::endl;
}