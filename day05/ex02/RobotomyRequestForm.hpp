#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP
# include "Form.hpp"

class	RobotomyRequestForm: public Form {
	public:
		~RobotomyRequestForm();
		RobotomyRequestForm(std::string target = "default");
		RobotomyRequestForm(const RobotomyRequestForm & cpy);
		void	execute(Bureaucrat const & executor) const;
};

#endif