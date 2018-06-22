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

//constructors
FragTrap::FragTrap(std::string name): ClapTrap(name) {
	std::cout << "Get ready for some Fragtrap face time!" << std::endl;
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

FragTrap::FragTrap(FragTrap const &cpy): ClapTrap(cpy){}

//destructor
FragTrap::~FragTrap(void) {
	std::cout << "Argh arghargh death gurgle gurglegurgle urgh... death." << std::endl;
	std::cout << "FragTrap " <<_name << " is dead! Rest in hell bastards!" << std::endl;
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