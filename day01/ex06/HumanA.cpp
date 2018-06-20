#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &weapon) {
	this->_name = name;
	this->_weapon = &weapon; 
}

HumanA::~HumanA( void ) {};

Weapon	HumanA::_dweapon = Weapon();

void	HumanA::attack( void ) {
	std::cout << this->_name;
	std::cout << " attacks with his ";
	std::cout << this->_weapon->getType() << std::endl;
}

void	HumanA::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}