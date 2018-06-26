#include "Bureaucrat.hpp"

int		main(void)
{
	try {
		Bureaucrat	bob("bob", 150);
		++bob;
		std::cout << bob << std::endl;
		bob--;
		std::cout << bob << std::endl;
		bob++;
		std::cout << bob << std::endl;
		--bob;
		std::cout << bob << std::endl;
		bob += 100;
		std::cout << bob << std::endl;
		bob -= 100;
		std::cout << bob << std::endl;
		bob.promote(100);
		std::cout << bob << std::endl;
		bob.demote(100);
		std::cout << bob << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}