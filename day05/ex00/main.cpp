#include "Bureaucrat.hpp"

int		main(void)
{
	try {
		Bureaucrat	bob("bob", 150);
		//Bureaucrat	bob("bob", 200);
		//bob.demote();
		std::cout << bob << std::endl;
		Bureaucrat	archi = Bureaucrat();
		std::cout << archi << std::endl;
		while (archi.getGrade() != 1) {
			archi.promote();
			std::cout << archi << std::endl;
		}
		//archi.promote();
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}