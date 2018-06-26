#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

int		main(void)
{
	try {
		srand(time(NULL));
		Intern *i = new Intern();
		Bureaucrat *s = new Bureaucrat("Bob", 50);
		Bureaucrat *e = new Bureaucrat("Archi", 25);
		OfficeBlock inferno(i, s, e);
		inferno.doBureaucracy("shrubbery creation", "Kovsh");
		inferno.doBureaucracy("robotomy request", "Kovsh");
		inferno.doBureaucracy("presidential pardon", "Kovsh");
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}