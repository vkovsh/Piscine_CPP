#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP
# include <iostream>

class	ScavTrap	{
	private:
		//const area
		const static int _meleeNbr = 4;
		const static int _rangedNbr = 4;
		const static int _typeNbr = 2;
		static std::string _meleeAttacks[_meleeNbr];
		static std::string _rangedAttacks[_rangedNbr];

		//static area
		static int	_maxHitPoints;
		static int	_maxEnergyPoints;

		//static getters
		static int	getMaxHitPoints(void);
		static int	getMaxEnergyPoints(void);

		//static setters
		static void	setMaxHitPoints(int points);
		static void setMaxEnergyPoints(int points);

		//attributes
		int			_hitPoints;
		int			_energyPoints;
		int			_level;
		std::string	_name;
		int			_meleeAttackDamage;
		int			_rangedAttackDamage;
		int			_armorDamageReduction;
		bool		_freezed;
	
	public:
		//constructors
		ScavTrap(std::string name = "ScavTrap");
		ScavTrap(ScavTrap const &cpy);

		//destructor
		~ScavTrap(void);

		//getters
		int			getHitPoints(void);
		int			getEnergyPoints(void);
		int			getLevel(void);
		std::string	getName(void);
		int			getMeleeAttackDamage(void);
		int			getRangedAttackDamage(void);
		int			getArmorDamageReduction(void);

		//setters
		void		setHitPoints(int n);
		void		setEnergyPoints(int n);
		void		setLevel(int n);
		void		setName(std::string name);
		void		setMeleeAttackDamage(int n);
		void		setRangedAttackDamage(int n);
		void		setArmorDamageReduction(int n);

		//methods
		void		rangedAttack(std::string const & target);
		void		meleeAttack(std::string const & target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		challengeNewcomer(std::string const & target);

		//operators oberloading
		ScavTrap	&operator = (const ScavTrap &cpy);
};

std::ostream		&operator << (std::ostream &o, const ScavTrap &cpy);

#endif