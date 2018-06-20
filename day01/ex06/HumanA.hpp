#ifndef HUMAN_A
# define HUMAN_A
# include "Weapon.hpp"

class	HumanA	{
	private:
		static Weapon	_dweapon;
		Weapon			*_weapon;
		std::string		_name;

	public:
		HumanA( std::string name = "Bob",
				Weapon &weapon = HumanA::_dweapon);
		~HumanA( void );

		void	attack( void );
		void	setWeapon(Weapon &weapon);
};

#endif