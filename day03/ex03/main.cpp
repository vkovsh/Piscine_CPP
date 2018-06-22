#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

int	main(void)
{
	ClapTrap mike("Mike");
	ScavTrap nick("Nick");
	FragTrap helen("Helen");
	NinjaTrap ninja("Kiyoshi");
	NinjaTrap ninja2("Abe");
	ninja.ninjaShoebox(ninja2);
	return (0);
}