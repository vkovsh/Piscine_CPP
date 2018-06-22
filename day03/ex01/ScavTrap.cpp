#include "ScavTrap.hpp"

std::string ScavTrap::_meleeAttacks[ScavTrap::_meleeNbr] = {"Laser knife", "Funzerker", "Devastating punch", "Paralising"};
std::string ScavTrap::_rangedAttacks[ScavTrap::_rangedNbr] = {"Devastating gun", "Infernal gun", "Laser Inferno", "Miniontrap"};

int	ScavTrap::_maxHitPoints = 100;
int	ScavTrap::_maxEnergyPoints = 50;

//static getters
int	ScavTrap::getMaxHitPoints(void) {
	return (ScavTrap::_maxHitPoints);
}

int	ScavTrap::getMaxEnergyPoints(void) {
	return (ScavTrap::_maxEnergyPoints);
}

//static setters
void ScavTrap::setMaxHitPoints(int points) {
	if (points > 0) {
		ScavTrap::_maxHitPoints = points;
	}
}

void ScavTrap::setMaxEnergyPoints(int points) {
	if (points > 0) {
		ScavTrap::_maxEnergyPoints = points;
	}
}

//constructors
ScavTrap::ScavTrap(std::string name): _name(name) {
	std::cout << "ScavTrap" << _name << " is alive!" << std::endl;
	std::cout << "ScavTrap ready for action!" << std::endl;
	_hitPoints = ScavTrap::_maxHitPoints;
	_energyPoints = ScavTrap::_maxEnergyPoints;
	_level = 1;
	_meleeAttackDamage = 20;
	_rangedAttackDamage = 15;
	_armorDamageReduction = 3;
	_freezed = false;
}

ScavTrap::ScavTrap(ScavTrap const &cpy) {
	if (this != &cpy)
		*this = cpy;
}

//destructor
ScavTrap::~ScavTrap(void) {
	std::cout << "Unit exterminated!" << std::endl;
	std::cout << "ScavTrap" << _name << " dead!" << std::endl;
}

//getters
int			ScavTrap::getHitPoints(void) {
	return (this->_hitPoints);
}

int			ScavTrap::getEnergyPoints(void) {
	return (this->_energyPoints);
}

int			ScavTrap::getLevel(void) {
	return (this->_level);
}

std::string	ScavTrap::getName(void) {
	return (this->_name);
}

int			ScavTrap::getMeleeAttackDamage(void) {
	return (this->_meleeAttackDamage);
}

int			ScavTrap::getRangedAttackDamage(void) {
	return (this->_rangedAttackDamage);
}

int			ScavTrap::getArmorDamageReduction(void) {
	return (this->_armorDamageReduction);
}

//setters
void		ScavTrap::setHitPoints(int n) {
	if (n <= ScavTrap::_maxHitPoints) {
		this->_hitPoints = n;
	}
}

void		ScavTrap::setEnergyPoints(int n) {
	if (n >= 0 && n <= ScavTrap::_maxEnergyPoints) {
		this->_energyPoints = n;
	}
}

void		ScavTrap::setLevel(int n) {
	if (n > 0 && n <= 90) {
		this->_level = n;
	}	
}

void		ScavTrap::setName(std::string name) {
	this->_name = name;
}

void		ScavTrap::setMeleeAttackDamage(int n) {
	if (n >= 0) {
		this->_meleeAttackDamage = n;
	} 
}

void		ScavTrap::setRangedAttackDamage(int n) {
	if (n >= 0) {
		this->_rangedAttackDamage = n;
	}
}

void		ScavTrap::setArmorDamageReduction(int n) {
	if (n >= 0) {
		this->_armorDamageReduction = n;
	}
}

ScavTrap	&ScavTrap::operator = (const ScavTrap &cpy) {
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
void		ScavTrap::rangedAttack(std::string const & target) {
	std::cout << "ScavTrap starting to catch a tarhet!" << std::endl;
	std::cout << "ScavTrap " << _name << " attacks ";
	std::cout << target << " at range, causing " << _rangedAttackDamage;
	std::cout << " points of damage !" << std::endl;
}

void		ScavTrap::meleeAttack(std::string const & target) {
	std::cout << "ScavTrap prepaires for a melee attack!" << std::endl;
	std::cout << "ScavTrap " << _name << " attacks ";
	std::cout << target << " at melee, causing " << _meleeAttackDamage;
	std::cout << " points of damage !" << std::endl;
}

void		ScavTrap::takeDamage(unsigned int amount) {
	int damage = amount - this->getArmorDamageReduction();
	if (damage < 0)
		damage = 0;
	int	nbr = this->getHitPoints() - damage;
	std::cout << "ScavTrap" << _name << " takes " << damage << " damage!" << std::endl;
	if (nbr <= 0) {
		this->setHitPoints(0);
		this->_freezed = true;
		std::cout << "ScavTrap " << _name << " freezed!" << std::endl;
	}
	else {
		this->setHitPoints(nbr);
	}
}

void		ScavTrap::beRepaired(unsigned int amount) {
	int nbr = this->getHitPoints() + amount;
	if (nbr > ScavTrap::getMaxHitPoints()) {
		nbr = ScavTrap::getMaxHitPoints();
	}
	int diff = nbr - this->getHitPoints();
	std::cout << _name << " recovered " << diff << " HP" << std::endl; 
	this->setHitPoints(nbr);
}

void		ScavTrap::challengeNewcomer(std::string const & target) {
	if (this->_freezed == true) {
		std::cout << "Cannot attack! I'm bleeding!" << std::endl;
	}
	else if (this->getEnergyPoints() >= 25) {
		int type = rand() % ScavTrap::_typeNbr;
		int index;
		//melee
		if (type == 0) {
			index = rand() % ScavTrap::_meleeNbr;
			std::cout << ScavTrap::_meleeAttacks[index] << std::endl;
			this->meleeAttack(target);
		}
		else if (type == 1) {
			index = rand() % ScavTrap::_rangedNbr;
			std::cout << ScavTrap::_rangedAttacks[index] << std::endl;
			this->rangedAttack(target);
		}
		this->_energyPoints -= 25;
	}
	else {
		std::cout << "ScavTrap" << _name << " out of energy!" << std::endl;
	}
}