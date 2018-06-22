#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
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
		ScavTrap(void);
		ScavTrap(std::string name = "ScavTrap");
		ScavTrap(ScavTrap const &cpy);
	
		//destructor
		~ScavTrap(void);

		//methods
		void		rangedAttack(std::string const & target);
		void		meleeAttack(std::string const & target);
		void		challengeNewcomer(std::string const & target);

		//operators oberloading
		ScavTrap	&operator = (const ScavTrap &cpy);
};

#endif