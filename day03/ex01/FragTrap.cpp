#include "FragTrap.hpp"

std::string FragTrap::_meleeAttacks[FragTrap::_meleeNbr] = {"Meat Unicycle", "Funzerker", "Senseless Sacrifice", "Rubber Ducky"};
std::string FragTrap::_rangedAttacks[FragTrap::_rangedNbr] = {"Clap-In-The-Box", "Torgue Fiesta", "Laser Inferno", "Miniontrap"};

int	FragTrap::_maxHitPoints = 100;
int	FragTrap::_maxEnergyPoints = 100;

//static getters
int	FragTrap::getMaxHitPoints(void) {
	return (FragTrap::_maxHitPoints);
}

int	FragTrap::getMaxEnergyPoints(void) {
	return (FragTrap::_maxEnergyPoints);
}

//static setters
void FragTrap::setMaxHitPoints(int points) {
	if (points > 0) {
		FragTrap::_maxHitPoints = points;
	}
}

void FragTrap::setMaxEnergyPoints(int points) {
	if (points > 0) {
		FragTrap::_maxEnergyPoints = points;
	}
}

//constructors
FragTrap::FragTrap(std::string name): _name(name) {
	std::cout << "FragTrap " << _name << " is alive!" << std::endl;
	std::cout << "Get ready for some Fragtrap face time!" << std::endl;
	_hitPoints = FragTrap::_maxHitPoints;
	_energyPoints = FragTrap::_maxEnergyPoints;
	_level = 1;
	_meleeAttackDamage = 30;
	_rangedAttackDamage = 20;
	_armorDamageReduction = 5;
	_freezed = false;
}

FragTrap::FragTrap(FragTrap const &cpy) {
	if (this != &cpy)
		*this = cpy;
}

//destructor
FragTrap::~FragTrap(void) {
	std::cout << "Argh arghargh death gurgle gurglegurgle urgh... death." << std::endl;
	std::cout << "FragTrap " <<_name << " is dead! Rest in hell bastards!" << std::endl;
}

//getters
int			FragTrap::getHitPoints(void) {
	return (this->_hitPoints);
}

int			FragTrap::getEnergyPoints(void) {
	return (this->_energyPoints);
}

int			FragTrap::getLevel(void) {
	return (this->_level);
}

std::string	FragTrap::getName(void) {
	return (this->_name);
}

int			FragTrap::getMeleeAttackDamage(void) {
	return (this->_meleeAttackDamage);
}

int			FragTrap::getRangedAttackDamage(void) {
	return (this->_rangedAttackDamage);
}

int			FragTrap::getArmorDamageReduction(void) {
	return (this->_armorDamageReduction);
}

//setters
void		FragTrap::setHitPoints(int n) {
	if (n <= FragTrap::_maxHitPoints) {
		this->_hitPoints = n;
	}
}

void		FragTrap::setEnergyPoints(int n) {
	if (n >= 0 && n <= FragTrap::_maxEnergyPoints) {
		this->_energyPoints = n;
	}
}

void		FragTrap::setLevel(int n) {
	if (n > 0 && n <= 90) {
		this->_level = n;
	}	
}

void		FragTrap::setName(std::string name) {
	this->_name = name;
}

void		FragTrap::setMeleeAttackDamage(int n) {
	if (n >= 0) {
		this->_meleeAttackDamage = n;
	} 
}

void		FragTrap::setRangedAttackDamage(int n) {
	if (n >= 0) {
		this->_rangedAttackDamage = n;
	}
}

void		FragTrap::setArmorDamageReduction(int n) {
	if (n >= 0) {
		this->_armorDamageReduction = n;
	}
}

FragTrap	&FragTrap::operator = (const FragTrap &cpy) {
	if(this == &cpy)
       return (*this);
	_name = cpy._name;
	_hitPoints = cpy._hitPoints;
	_energyPoints = cpy._energyPoints;
	_level = cpy._level;
	_meleeAttackDamage = cpy._meleeAttackDamage;
	_rangedAttackDamage = cpy._rangedAttackDamage;
	_armorDamageReduction = cpy._armorDamageReduction;
	_freezed = cpy._freezed;
	return (*this);

}

//methods
void		FragTrap::rangedAttack(std::string const & target) {
	std::cout << "I'm a tornado of death and bullets!" << std::endl;
	std::cout << "FragTrap " << _name << " attacks ";
	std::cout << target << " at range, causing " << _rangedAttackDamage;
	std::cout << " points of damage !" << std::endl;
}

void		FragTrap::meleeAttack(std::string const & target) {
	std::cout << "Pain school is now in session!" << std::endl;
	std::cout << "FragTrap " << _name << " attacks ";
	std::cout << target << " at melee, causing " << _meleeAttackDamage;
	std::cout << " points of damage !" << std::endl;
}

void		FragTrap::takeDamage(unsigned int amount) {
	int damage = amount - this->getArmorDamageReduction();
	if (damage < 0)
		damage = 0;
	int	nbr = this->getHitPoints() - damage;
	std::cout << "FragTrap " << _name << " takes " << damage << " damage!" << std::endl;
	if (nbr <= 0) {
		this->setHitPoints(0);
		this->_freezed = true;
		std::cout << "FragTrap " << _name << " needs help!" << std::endl;
	}
	else {
		this->setHitPoints(nbr);
	}
}

void		FragTrap::beRepaired(unsigned int amount) {
	int nbr = this->getHitPoints() + amount;
	if (nbr > FragTrap::getMaxHitPoints()) {
		nbr = FragTrap::getMaxHitPoints();
	}
	int diff = nbr - this->getHitPoints();
	std::cout << "FragTrap " << _name << " recovered " << diff << " HP" << std::endl; 
	this->setHitPoints(nbr);
}

void		FragTrap::vaulthunter_dot_exe(std::string const & target) {
	if (_freezed == true) {
		std::cout << "FragTrap " << _name << " freezed!" << std::endl;
	}
	else if (this->getEnergyPoints() >= 25) {
		int type = rand() % FragTrap::_typeNbr;
		int index;
		//melee
		if (type == 0) {
			index = rand() % FragTrap::_meleeNbr;
			std::cout << FragTrap::_meleeAttacks[index] << std::endl;
			this->meleeAttack(target);
		}
		else if (type == 1) {
			index = rand() % FragTrap::_rangedNbr;
			std::cout << FragTrap::_rangedAttacks[index] << std::endl;
			this->rangedAttack(target);
		}
		this->_energyPoints -= 25;
	}
	else {
		std::cout << "FragTrap " << _name << " out of energy!" << std::endl;
	}
}