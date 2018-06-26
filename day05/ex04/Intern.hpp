#ifndef INTERN_HPP
# define INTERN_HPP
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class	Intern	{
	private:
		Form	*makeRobotomyRequestForm(std::string target);
		Form	*makeShrubberyCreationForm(std::string target);
		Form	*makePresidentialPardonForm(std::string target);

	public:
		Intern();
		~Intern();
		Form	*makeForm(std::string formName, std::string target);
};

#endif