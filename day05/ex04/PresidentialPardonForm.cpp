#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("PresidentialPardonForm", target, 25, 5, false) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & cpy): Form(cpy) {}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
  if (getStatus() == false) {
    throw _e;
  }
  else if (getExecGrade() < executor.getGrade()) {
    throw _l;
  }
  else {
	  std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
  }
}