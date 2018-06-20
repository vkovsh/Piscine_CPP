#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent( void ) {};

ZombieEvent::~ZombieEvent( void ) {};

void	ZombieEvent::setZombieType( std::string ztype) {
	this->_ztype = ztype;
}

std::string	ZombieEvent::GetZombieType( void ) {
	return (this->_ztype);
}

Zombie	*ZombieEvent::newZombie(std::string name) {
	Zombie	*zombie = new Zombie(name, this->GetZombieType());
	return (zombie);
}

Zombie	*ZombieEvent::randomChump( void ) {
	std::string random_name;
	random_name = Zombie::GetNameFromList(std::rand() % 20);
	Zombie *zombie = new Zombie(random_name, this->GetZombieType());
	return (zombie);
}
