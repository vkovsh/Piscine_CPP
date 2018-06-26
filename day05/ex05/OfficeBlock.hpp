#ifndef OFFICE_BLOCK_HPP
# define OFFICE_BLOCK_HPP
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

class	OfficeBlock	{
	private:
		Intern		*_intern;
		Bureaucrat	*_secretary;
		Bureaucrat	*_executor;

	public:
		~OfficeBlock();
		OfficeBlock(Intern *slave, Bureaucrat *secretary, Bureaucrat *executor);
		OfficeBlock();
		void	setIntern(Intern *newSlave);
		void	setSecretary(Bureaucrat *newSecretary);
		void	setExecutor(Bureaucrat *newExecuror);
		Form	*doBureaucracy(std::string formName, std::string target);
};

#endif