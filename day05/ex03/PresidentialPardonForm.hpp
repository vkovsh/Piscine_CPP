#ifndef PRESIDENTAL_PARDON_FORM_HPP
# define PRESIDENTAL_PARDON_FORM_HPP
# include "Form.hpp"

class	PresidentialPardonForm: public Form {
	public:
		~PresidentialPardonForm();
		PresidentialPardonForm(std::string target = "default");
		PresidentialPardonForm(const PresidentialPardonForm & cpy);
		void	execute(Bureaucrat const & executor) const;
};

#endif