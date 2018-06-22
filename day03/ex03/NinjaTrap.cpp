#include "NinjaTrap.hpp"

std::string NinjaTrap::_meleeAttacks[NinjaTrap::_meleeNbr] = {"Leg jutsu", "Dead punch", "Head jutsu", "Bushido codex"};
std::string NinjaTrap::_rangedAttacks[NinjaTrap::_rangedNbr] = {"Night shadow", "Fear", "Death", "Robber"};

int	NinjaTrap::_maxHitPoints = 60;
int	NinjaTrap::_maxEnergyPoints = 120;

//static getters
int	NinjaTrap::getMaxHitPoints(void) {
	return (NinjaTrap::_maxHitPoints);
}

int	NinjaTrap::getMaxEnergyPoints(void) {
	return (NinjaTrap::_maxEnergyPoints);
}

//constructors
NinjaTrap::NinjaTrap(std::string name): ClapTrap(name) {
	std::cout << "I'm a death of night..." << std::endl;
	std::cout << "NinjaTrap " << _name << " is alive!" << std::endl;
	_hitPoints = NinjaTrap::_maxHitPoints;
	_energyPoints = NinjaTrap::_maxEnergyPoints;
	_level = 1;
	_meleeAttackDamage = 60;
	_rangedAttackDamage = 5;
	_armorDamageReduction = 0;
	_freezed = false;
}

NinjaTrap::NinjaTrap(NinjaTrap const &cpy): ClapTrap(cpy){}

//destructor
NinjaTrap::~NinjaTrap(void) {
	std::cout << "I'm dead, but spirit of samurai is alive." << std::endl;
}

NinjaTrap	&NinjaTrap::operator = (const NinjaTrap &cpy) {
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
void		NinjaTrap::rangedAttack(std::string const & target) {
	std::cout << "My suriken willf find you!" << std::endl;
	std::cout << "NinjaTrap " << _name << " attacks ";
	std::cout << target << " at range, causing " << _rangedAttackDamage;
	std::cout << " points of damage !" << std::endl;
}

void		NinjaTrap::meleeAttack(std::string const & target) {
	std::cout << "Pain school is now in session!" << std::endl;
	std::cout << "NinjaTrap " << _name << " attacks ";
	std::cout << target << " at melee, causing " << _meleeAttackDamage;
	std::cout << " points of damage !" << std::endl;
}

void		NinjaTrap::ninjaShoebox(FragTrap & target) {
	int attack_type = rand() % 2;
	int index;
	if (_freezed == true) {
		std::cout << "NinjaTrap " << _name << " freezed!" << std::endl;
	}
	else if (this->getEnergyPoints() >= 25) {
		if (attack_type == 0) {
			index = rand() % NinjaTrap::_meleeNbr;
			std::cout << NinjaTrap::_meleeAttacks[index] << std::endl;
			this->meleeAttack(target.getName());
			target.takeDamage(NinjaTrap::_meleeAttackDamage);
		}
		else if (attack_type == 1) {
			index = rand() % NinjaTrap::_rangedNbr;
			std::cout << NinjaTrap::_rangedAttacks[index] << std::endl;
			this->rangedAttack(target.getName());
			target.takeDamage(NinjaTrap::_meleeAttackDamage);
		}
	}
	else {
		std::cout << "NinjaTrap" << _name << " out of energy!" << std::endl;
	}
}

void		NinjaTrap::ninjaShoebox(ScavTrap & target) {
	int attack_type = rand() % 2;
	int index;
	if (_freezed == true) {
		std::cout << "NinjaTrap " << _name << " freezed!" << std::endl;
	}
	else if (this->getEnergyPoints() >= 25) {
		if (attack_type == 0) {
			index = rand() % NinjaTrap::_meleeNbr;
			std::cout << NinjaTrap::_meleeAttacks[index] << std::endl;
			this->meleeAttack(target.getName());
			target.takeDamage(NinjaTrap::_meleeAttackDamage);
		}
		else if (attack_type == 1) {
			index = rand() % NinjaTrap::_rangedNbr;
			std::cout << NinjaTrap::_rangedAttacks[index] << std::endl;
			this->rangedAttack(target.getName());
			target.takeDamage(NinjaTrap::_meleeAttackDamage);
		}
	}
	else {
		std::cout << "NinjaTrap" << _name << " out of energy!" << std::endl;
	}
}

void		NinjaTrap::ninjaShoebox(NinjaTrap & target) {
	int attack_type = rand() % 2;
	int index;
	if (_freezed == true) {
		std::cout << "NinjaTrap " << _name << " freezed!" << std::endl;
	}
	else if (this->getEnergyPoints() >= 25) {
		if (attack_type == 0) {
			index = rand() % NinjaTrap::_meleeNbr;
			std::cout << NinjaTrap::_meleeAttacks[index] << std::endl;
			this->meleeAttack(target.getName());
			target.takeDamage(NinjaTrap::_meleeAttackDamage);
		}
		else if (attack_type == 1) {
			index = rand() % NinjaTrap::_rangedNbr;
			std::cout << NinjaTrap::_rangedAttacks[index] << std::endl;
			this->rangedAttack(target.getName());
			target.takeDamage(NinjaTrap::_meleeAttackDamage);
		}
	}
	else {
		std::cout << "NinjaTrap" << _name << " out of energy!" << std::endl;
	}
}