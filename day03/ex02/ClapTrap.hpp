#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP
# include <iostream>

class	ClapTrap {
	//static area
	private:
		static int	_maxHitPoints;
		static int	_maxEnergyPoints;
		//static getters
		static int	getMaxHitPoints(void);
		static int	getMaxEnergyPoints(void);
		
	protected:

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

		ClapTrap(void);
	
	public:
		//constructors
		ClapTrap(std::string name = "ClapTrap");
		ClapTrap(ClapTrap const &cpy);

		//destructor
		~ClapTrap(void);

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
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		//operators oberloading
		ClapTrap	&operator = (const ClapTrap &cpy);
};

#endif