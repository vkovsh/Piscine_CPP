#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("RobotomyRequestForm", target, 72, 45, false) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & cpy): Form(cpy) {}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
  if (getStatus() == false) {
    throw _e;
  }
  else if (getExecGrade() < executor.getGrade()) {
    throw _l;
  }
  else {
	  std::cout << "BzBzBz" << std::endl;
	  bool success = rand() % 2;
	  if (success) {
		  std::cout << getTarget() << " robotimized successfully!" << std::endl;
	  }
	  else {
		  std::cout << "Failure!" << std::endl;
	  }
  }
}