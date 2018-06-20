#include "Brain.hpp"

Brain::Brain( int iq ): _iq(iq) {
	std::ostringstream adress;
	adress << (void const *)this;
	this->_adress = adress.str();
}

Brain::~Brain( void ) {}
		
int	Brain::GetIq( void ) {
	return (this->_iq);
}

std::string Brain::identify( void ) const{
	return (this->_adress);
}