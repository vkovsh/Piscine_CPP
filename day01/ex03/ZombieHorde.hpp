#ifndef ZOMBIE_HORDE_H
# define ZOMBIE_HORDE_H
# include "Zombie.hpp"
# include <iostream>
# include <cstdlib>

class	ZombieHorde	{
	private:
		Zombie	**_zombies;
		int		_zcount;

		ZombieHorde( void );

	public:
		void	announce( void );

		ZombieHorde( int n = 1 );

		~ZombieHorde( void );
};

#endif