#include "Human.hpp"

Human::Human( std::string name ): _name(name) {};

Human::~Human ( void ) {}

const Brain	&Human::getBrain( void ) {
	return (this->_brain);
}

std::string	Human::identify() const{
	return (this->_brain.identify());
}