#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int		main(void)
{
	try {
		srand ( time(NULL) );
		Bureaucrat	bob("Bob", 1);
		std::cout << bob << std::endl;
		ShrubberyCreationForm tree("House2");
		tree.beSigned(bob);
		tree.execute(bob);
		std::cout << tree << std::endl;

		Bureaucrat	archi("Archi", 100);
		std::cout << archi << std::endl;
		ShrubberyCreationForm tree2("House3");
		archi.signForm(tree2);
		archi.executeForm(tree2);
		std::cout << tree2 << std::endl;

		RobotomyRequestForm robot("Ashley");
		std::cout << robot << std::endl;
		RobotomyRequestForm robot2(robot);
		std::cout << robot2 << std::endl;
		robot.beSigned(bob);
		robot.execute(bob);
		robot.execute(bob);
		robot.execute(bob);
		robot.execute(bob);
		robot.execute(bob);
		robot.execute(bob);

		PresidentialPardonForm pres("Gandi");
		std::cout << pres << std::endl;
		pres.beSigned(bob);
		pres.execute(bob);
		bob.executeForm(pres);

		Intern  someRandomIntern;
		Form*   rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}