#ifndef NINJA_TRAP_HPP
# define NINJA_TRAP_HPP
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class	NinjaTrap: public ClapTrap {
	//static area
	private:
		static int	_maxHitPoints;
		static int	_maxEnergyPoints;
		//static getters
		static int	getMaxHitPoints(void);
		static int	getMaxEnergyPoints(void);
		
		//const area
		const static int _meleeNbr = 4;
		const static int _rangedNbr = 4;
		const static int _typeNbr = 2;
		static std::string _meleeAttacks[_meleeNbr];
		static std::string _rangedAttacks[_rangedNbr];

	public:
		//constructors
		NinjaTrap(std::string name = "NinjaTrap");
		NinjaTrap(NinjaTrap const &cpy);
	
		//destructor
		~NinjaTrap(void);

		//methods
		void		rangedAttack(std::string const & target);
		void		meleeAttack(std::string const & target);
		void		ninjaShoebox(FragTrap & target);
		void		ninjaShoebox(ScavTrap & target);
		void		ninjaShoebox(NinjaTrap & target);

		//operators overloading
		NinjaTrap	&operator = (const NinjaTrap &cpy);
};

#endif