#include "Form.hpp"

Form::Form(): _name("default"), _sign(150), _exec(150) {
	_signed = false;
}

Form::~Form() {};

void	Form::execute(Bureaucrat const & executor) const {
	std::cout << executor << std::endl;
}

Form::Form(std::string name, std::string target, int sign, int exec, bool is_signed): _target(target), _name(name), _sign(sign), _exec(exec) {
	_signed = is_signed;
	if (sign > 150 || exec > 150) {
		throw _l;
	}
	else if (sign < 1 || exec < 1) {
		throw _h;
	}
}

Form::Form(const Form & cpy): _target(cpy._target), _name(cpy._name), _sign(cpy._sign), _exec(cpy._exec) {
	*this = cpy;
}

std::string	Form::getName() const {
	return _name;
}

int			Form::getSignGrade() const {
	return _sign;
}

int			Form::getExecGrade() const {
	return _exec;
}

bool		Form::getStatus() const {
	return _signed;
}

std::string	Form::getTarget() const {
	return _target;
}

Form		&Form::operator = (const Form &cpy) {
	_signed = cpy.getStatus();
	return (*this);
}

void		Form::beSigned(const Bureaucrat & duty) {
	if (duty.getGrade() <= _sign) {
		_signed = true;
	}
	else {
		throw _l;
	}
}

std::ostream	&operator << (std::ostream &o, const Form &cpy) {
	o << "Form " << cpy.getName() << " needs " << cpy.getSignGrade() << " to sign and " << cpy.getExecGrade() << " to execute";
	return o;
}
