#include "HumanB.hpp"

HumanB::HumanB( std::string name, Weapon &weapon) {
	this->_name = name;
	this->_weapon = &weapon;
}

HumanB::~HumanB( void ) {};

Weapon	HumanB::_dweapon = Weapon();

void	HumanB::attack( void ) {
	std::cout << this->_name;
	std::cout << " attacks with his ";
	std::cout << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}