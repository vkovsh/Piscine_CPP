#include "ClapTrap.hpp"

int	ClapTrap::_maxHitPoints = 100;
int	ClapTrap::_maxEnergyPoints = 100;

ClapTrap::ClapTrap(void){}

//static getters
int	ClapTrap::getMaxHitPoints(void) {
	return (ClapTrap::_maxHitPoints);
}

int	ClapTrap::getMaxEnergyPoints(void) {
	return (ClapTrap::_maxEnergyPoints);
}

//static setters
void ClapTrap::setMaxHitPoints(int points) {
	if (points > 0) {
		ClapTrap::_maxHitPoints = points;
	}
}

void ClapTrap::setMaxEnergyPoints(int points) {
	if (points > 0) {
		ClapTrap::_maxEnergyPoints = points;
	}
}

//constructors
ClapTrap::ClapTrap(std::string name): _name(name) {
	std::cout << "ClapTrap " << _name << " is alive!" << std::endl;
	_hitPoints = ClapTrap::_maxHitPoints;
	_energyPoints = ClapTrap::_maxEnergyPoints;
	_level = 1;
	_meleeAttackDamage = 30;
	_rangedAttackDamage = 20;
	_armorDamageReduction = 5;
	_freezed = false;
}

ClapTrap::ClapTrap(ClapTrap const &cpy) {
	std::cout << "ClapTrap " << cpy._name << " cloned!" << std::endl;
	if (this != &cpy)
		*this = cpy;
}

//destructor
ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap " <<_name << " is dead" << std::endl;
}

//getters
int			ClapTrap::getHitPoints(void) {
	return (this->_hitPoints);
}

int			ClapTrap::getEnergyPoints(void) {
	return (this->_energyPoints);
}

int			ClapTrap::getLevel(void) {
	return (this->_level);
}

std::string	ClapTrap::getName(void) const {
	return (this->_name);
}

int			ClapTrap::getMeleeAttackDamage(void) {
	return (this->_meleeAttackDamage);
}

int			ClapTrap::getRangedAttackDamage(void) {
	return (this->_rangedAttackDamage);
}

int			ClapTrap::getArmorDamageReduction(void) {
	return (this->_armorDamageReduction);
}

//setters
void		ClapTrap::setHitPoints(int n) {
	if (n <= ClapTrap::_maxHitPoints) {
		this->_hitPoints = n;
	}
}

void		ClapTrap::setEnergyPoints(int n) {
	if (n >= 0 && n <= ClapTrap::_maxEnergyPoints) {
		this->_energyPoints = n;
	}
}

void		ClapTrap::setLevel(int n) {
	if (n > 0 && n <= 90) {
		this->_level = n;
	}	
}

void		ClapTrap::setName(std::string name) {
	this->_name = name;
}

void		ClapTrap::setMeleeAttackDamage(int n) {
	if (n >= 0) {
		this->_meleeAttackDamage = n;
	} 
}

void		ClapTrap::setRangedAttackDamage(int n) {
	if (n >= 0) {
		this->_rangedAttackDamage = n;
	}
}

void		ClapTrap::setArmorDamageReduction(int n) {
	if (n >= 0) {
		this->_armorDamageReduction = n;
	}
}

ClapTrap	&ClapTrap::operator = (const ClapTrap &cpy) {
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

void		ClapTrap::takeDamage(unsigned int amount) {
	int damage = amount - this->getArmorDamageReduction();
	if (damage < 0)
		damage = 0;
	int	nbr = this->getHitPoints() - damage;
	std::cout << "ClapTrap " << _name << " takes " << damage << " damage!" << std::endl;
	if (nbr <= 0) {
		this->setHitPoints(0);
		this->_freezed = true;
		std::cout << "ClapTrap " << _name << " needs help!" << std::endl;
	}
	else {
		this->setHitPoints(nbr);
	}
}

void		ClapTrap::beRepaired(unsigned int amount) {
	int nbr = this->getHitPoints() + amount;
	if (nbr > ClapTrap::getMaxHitPoints()) {
		nbr = ClapTrap::getMaxHitPoints();
	}
	int diff = nbr - this->getHitPoints();
	std::cout << "ClapTrap " << _name << " recovered " << diff << " HP" << std::endl; 
	this->setHitPoints(nbr);
}