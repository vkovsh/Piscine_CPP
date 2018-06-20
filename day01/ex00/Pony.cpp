#include "Pony.hpp"

Pony::Pony( std::string name ): _name(name) {
	std::cout << "Pony " << name;
	std::cout << " is alive!" << std::endl;
}

Pony::~Pony( void ) {
	std::cout << this->_name << " dies!";
	std::cout << std::endl;
}

std::string	Pony::GetName( void ) {
	return (this->_name);
}

std::string	Pony::GetColor( void ) {
	return (this->_color);
}