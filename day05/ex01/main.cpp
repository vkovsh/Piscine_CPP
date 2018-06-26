#include "Bureaucrat.hpp"

int		main(void)
{
	try {
		Bureaucrat	bob("Bob", 150);
		std::cout << bob << std::endl;
		Bureaucrat	archi("Archi", 1);
		std::cout << archi << std::endl;
		Form a("formA", 1);
		std::cout << a << std::endl;
		a.beSigned(archi);
		//bob.signForm(a);
		//a.beSigned(bob);
		//a.beSigned(archi);
		std::cout << a << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}