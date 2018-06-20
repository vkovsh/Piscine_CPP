#ifndef HUMAN_B
# define HUMAN_B
# include "Weapon.hpp"

class	HumanB	{
	private:
		static Weapon	_dweapon;
		Weapon			*_weapon;
		std::string		_name;

	public:
		HumanB( std::string name = "Bob",
				Weapon &weapon = HumanB::_dweapon);
		~HumanB( void );

		void	attack( void );
		void	setWeapon(Weapon &weapon);
};

#endif