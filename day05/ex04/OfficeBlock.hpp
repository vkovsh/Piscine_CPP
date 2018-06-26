#ifndef OFFICE_BLOCK_HPP
# define OFFICE_BLOCK_HPP
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

class	OfficeBlock	{
	public:
		~OfficeBlock();
		OfficeBlock(Intern *slave, Bureaucrat *secretary, Bureaucrat *executor);
		
};

#endif