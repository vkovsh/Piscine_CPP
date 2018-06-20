#include "Zombie.hpp"

std::string Zombie::_names[Zombie::_nameCount] = {"Fenton", "Ferebee", "Fielder", "Fielding", "Filmore",	\
															"Finch", "Finch", "Finesse", "Finnick", "Fisk",			\
															"Fitzhugh", "Fitzroy", "Fitzwilliam", "Flash", "Fleet",	\
    														"Fleetwood", "Fleming", "Fletcher", "Flint", "Ford"};



std::string Zombie::GetNameFromList( int index ) {
	if (index >= 0 && index < Zombie::_nameCount)
		return (Zombie::_names[index]);
	return ("Error");
}

Zombie::Zombie( void ): _name("Unknown"), _type("Infected") {};

Zombie::Zombie( std::string name): _name(name) {};

Zombie::Zombie( std::string name,
				std::string type): _name(name), _type(type) {};

Zombie::~Zombie( void ) {};

void	Zombie::announce( void ) {
	std::cout << "<" << this->_name;
	std::cout << " (" << this->_type << ")>";
	std::cout << " Braiiiiiiinnnssss...";
	std::cout << std::endl;
}