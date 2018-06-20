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

Zombie::Zombie( std::string name,
				std::string type):
				_name(name), _type(type) {
	std::cout << "Zombie " << name << " created" << std::endl;
}

Zombie::~Zombie( void ) {
	std::cout << "Zombie " << this->_name << " dismissed" << std::endl;
}

void	Zombie::announce( void ) {
	std::cout << "<" << this->_name;
	std::cout << " (" << this->_type << ")>";
	std::cout << " Braiiiiiiinnnssss...";
	std::cout << std::endl;
}

int		Zombie::GetNameCount( void ) {
	return (Zombie::_nameCount);
}