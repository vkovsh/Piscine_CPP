#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap a("Mike");
	ClapTrap b(a);
	ScavTrap c("Nick");
	ScavTrap d(c);
	FragTrap e("Helen");
	FragTrap f(e);
	return (0);
}