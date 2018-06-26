#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP
# include "Form.hpp"

class	ShrubberyCreationForm: public Form {
	public:
		~ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target = "default");
		ShrubberyCreationForm(const ShrubberyCreationForm & cpy);
		void				execute(Bureaucrat const & executor) const;
};
#endif