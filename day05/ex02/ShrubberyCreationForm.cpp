#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("ShrubberyCreationForm", target, 145, 137, false) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & cpy): Form(cpy) {}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
  if (getStatus() == false) {
    throw _e;
  }
  else if (getExecGrade() < executor.getGrade()) {
    throw _l;
  }
  else {
    std::string path = getTarget() + "_shrubbery"; 
    std::ofstream ofs(path.c_str(), std::ofstream::out | std::ofstream::app);
    std::ifstream ifs("tree");
    std::string tree;
    while (ifs.eof() == false) {
      std::string buf;
      getline(ifs, buf);
      tree = tree + '\n' + buf;
    }
    ofs << tree << std::endl;
    ofs.close();
    ifs.close();
  }
}