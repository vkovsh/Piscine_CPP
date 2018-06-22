#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP
# include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
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
		FragTrap(std::string name = "FragTrap");
		FragTrap(FragTrap const &cpy);
	
		//destructor
		~FragTrap(void);

		//methods
		void		rangedAttack(std::string const & target);
		void		meleeAttack(std::string const & target);
		void		vaulthunter_dot_exe(std::string const & target);

		//operators oberloading
		FragTrap	&operator = (const FragTrap &cpy);
};

#endif