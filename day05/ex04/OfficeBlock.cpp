#include "OfficeBlock.hpp"

OfficeBlock::~OfficeBlock() {}
OfficeBlock::OfficeBlock(Intern *slave, Bureaucrat *secretary, Bureaucrat *executor) {
	_intern = slave;
	_secretary = secretary;
	_executor = executor;
}

OfficeBlock::OfficeBlock(): _intern(NULL), _secretary(NULL), _executor(NULL) {}

void	OfficeBlock::setIntern(Intern *newSlave) {
	delete _intern;
	_intern = newSlave;
}

void	OfficeBlock::setSecretary(Bureaucrat *newSecretary) {
	delete _secretary;
	_secretary = newSecretary;
}

void	OfficeBlock::setExecutor(Bureaucrat *newExecuror) {
	delete _executor;
	_executor = newExecuror;
}
Form	*OfficeBlock::doBureaucracy(std::string formName, std::string target) {
	Form *form = _intern->makeForm(formName, target);
	form->beSigned(*_secretary);
	form->execute(*_executor);
	return form;
}