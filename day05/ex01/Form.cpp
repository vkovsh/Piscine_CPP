#include "Form.hpp"

Form::~Form(){}

Form::Form(): _name("default"), _grade(150) {
	_signed = false;
}

Form::Form(std::string name, int grade, bool is_signed): _name(name), _grade(grade) {
	_signed = is_signed;
	if (grade > 150) {
		throw _l;
	}
	else if (grade < 1) {
		throw _h;
	}
}

Form::Form(const Form & cpy): _name(cpy._name), _grade(cpy._grade) {
	_signed = cpy._signed;	
	*this = cpy;
}

std::string	Form::getName() const {
	return _name;
}

int			Form::getGrade() const {
	return _grade;
}

bool		Form::getStatus() const {
	return _signed;
}

Form		&Form::operator = (const Form &cpy) {
	_signed = cpy.getStatus();
	return (*this);
}

void		Form::beSigned(const Bureaucrat & duty) {
	if (duty.getGrade() <= _grade) {
		_signed = true;
	}
	else {
		throw _l;
	}
}

std::ostream	&operator << (std::ostream &o, const Form &cpy) {
	o << "Form " << cpy.getName() << " of grade " << cpy.getGrade();
	return o;
}
