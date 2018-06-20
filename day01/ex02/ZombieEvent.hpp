#ifndef ZOMBIE_EVENT_H
# define ZOMBIE_EVENT_H
# include <iostream>
# include "Zombie.hpp"
# include <ctime>
# include <cstdlib>

class	ZombieEvent {
	private:
		std::string	_ztype;
		
	public:
		std::string	GetZombieType( void );

		void	setZombieType( std::string ztype);
		Zombie	*newZombie( std::string name );
		Zombie	*randomChump( void );

		ZombieEvent( void );
		~ZombieEvent( void );
};

#endif