#include "FragTrap.hpp"

int	main(void) {
	FragTrap archi("Archi");
	archi.vaulthunter_dot_exe("Nick");
	archi.vaulthunter_dot_exe("Nick");
	archi.vaulthunter_dot_exe("Nick");
	archi.vaulthunter_dot_exe("Nick");
	archi.vaulthunter_dot_exe("Nick");
	archi.takeDamage(30);
	archi.beRepaired(20);
	archi.beRepaired(200);
	FragTrap mike("Mike");
	mike.vaulthunter_dot_exe("Nick");
	mike.vaulthunter_dot_exe("Nick");
	mike.vaulthunter_dot_exe("Nick");
	mike.vaulthunter_dot_exe("Nick");
	mike.vaulthunter_dot_exe("Nick");
}