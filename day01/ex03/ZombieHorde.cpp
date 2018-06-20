#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde( void ) {};

ZombieHorde::~ZombieHorde( void ) {
	std::cout << "Horde dismissed!" << std::endl;
	for (int i = 0; i < this->_zcount; ++i) {
		delete this->_zombies[i];
	}
	delete this->_zombies;
}

ZombieHorde::ZombieHorde( int n ): _zcount(n) {
	if (n > 0) {
		this->_zombies = new Zombie *[n];
		for (int i = 0; i < n; ++i) {
			this->_zombies[i] = new Zombie(Zombie::GetNameFromList(rand() % 20));
		}
	}
	else {
		std::cout << "Bad horde size! Cancelled" << std::endl;  
		delete this;
	}
}

void ZombieHorde::announce( void ) {
	for (int i = 0; i < this->_zcount; ++i) {
		this->_zombies[i]->announce();
	}
}