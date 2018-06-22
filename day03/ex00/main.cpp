#include "FragTrap.hpp"

int	main(void) {
	FragTrap *archi = new FragTrap("Archi");
	archi->vaulthunter_dot_exe("Nick");
	archi->vaulthunter_dot_exe("Nick");
	archi->vaulthunter_dot_exe("Nick");
	archi->vaulthunter_dot_exe("Nick");
	archi->vaulthunter_dot_exe("Nick");
	archi->takeDamage(30);
	FragTrap *mike = new FragTrap("Mike");
	mike = archi;
	mike->setEnergyPoints(100);
	archi->beRepaired(20);
	archi->takeDamage(1000);
	archi->beRepaired(20);
	mike->setName("Mike");
	mike->takeDamage(1000);
	mike->vaulthunter_dot_exe("Nick");
	mike->vaulthunter_dot_exe("Nick");
	mike->vaulthunter_dot_exe("Nick");
	mike->vaulthunter_dot_exe("Nick");
	mike->vaulthunter_dot_exe("Nick");
	mike->takeDamage(80);
}