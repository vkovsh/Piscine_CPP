#include <iostream>

int				main(int ac, char **av)
{
	int			i;
	int			j;
	std::locale	loc;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else 
	{
		i = 0;
		while (++i < ac)
		{
			j = -1;
			while (av[i][++j])
				std::cout << toupper(av[i][j], loc);
		}
		std::cout << std::endl;
	}
	return (0);
}