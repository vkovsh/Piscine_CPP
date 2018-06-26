#ifndef CENTRAL_BUREAUCRACY_HPP
# define CENTRAL_BUREAUCRACY_HPP
# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Intern.hpp"
# include "OfficeBlock.hpp"

class	CentralBureaucracy	{
	private:
		OfficeBlock	*_blocks[20];

	public:
		CentralBureaucracy();
		~CentralBureaucracy();
		OfficeBlock	*getBlock(int index);
};

#endif