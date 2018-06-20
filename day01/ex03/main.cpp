#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int	main( void ) {
	std::cout << "It seems like zombies gather into hordes!" << std::endl;
	std::cout << "Create 10 zombies" << std::endl;
	ZombieHorde *horde = new ZombieHorde(10);
	std::cout << "Horde announce:" << std::endl;
	horde->announce();
	delete horde;
	return (0);
}