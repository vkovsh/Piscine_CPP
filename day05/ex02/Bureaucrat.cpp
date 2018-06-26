#include "Bureaucrat.hpp"

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _rank(grade){
	if (grade > 150) {
		throw _l;
	}
	else if (grade < 1) {
		throw _h;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat & cpy) {
	*this = cpy;
}

Bureaucrat	&Bureaucrat::Bureaucrat::operator = (const Bureaucrat &cpy) {
	_rank = cpy._rank;
	return (*this);
}

std::ostream	&operator << (std::ostream &o, const Bureaucrat &cpy) {
	
	o << cpy.getName() << ", bureaucrat grade " << cpy.getGrade();
	return o;
}

std::string		Bureaucrat::getName() const {
	return _name;
}

int				Bureaucrat::getGrade() const {
	return _rank;
}

void			Bureaucrat::promote(unsigned int count) {
	if (_rank - count >= 1) {
		_rank -= count;
	}
	else {
		throw _h;
	}
}

void			Bureaucrat::demote(unsigned int count) {
	if (_rank + count <= 150) {
		_rank += count;
	}
	else {
		throw _l;
	}
}

Bureaucrat			&Bureaucrat::operator += (unsigned int count) {
	if (_rank - count >= 1) {
		_rank -= count;
	}
	else {
		throw _h;
	}
	return *this;
}

Bureaucrat			&Bureaucrat::operator -= (unsigned int count) {
	if (_rank + count <= 150) {
		_rank += count;
	}
	else {
		throw _l;
	}
	return *this;
}

Bureaucrat			&Bureaucrat::operator++(void) {
	if (_rank > 1) {
		_rank--;
	}
	else {
		throw _h;
	}
	return (*this);
}

Bureaucrat			Bureaucrat::operator++(int) {
	Bureaucrat temp = *this;
	++*this;
	return (temp);
}

Bureaucrat			&Bureaucrat::operator--(void) {
	if (_rank < 150) {
		_rank++;
	}
	else {
		throw _l;
	}
	return (*this);
}

Bureaucrat			Bureaucrat::operator--(int) {
	Bureaucrat temp = *this;
	--*this;
	return (temp);
}

void			Bureaucrat::signForm(Form & form) const {
	if (form.getStatus() == true) {
		std::cout << this << " cannot sign " << form << " because it's already signed!" << std::endl;
	}
	else if (_rank <= form.getSignGrade()) {
		form.beSigned(*this);
		std::cout << *this << " signs " << form << std::endl;
	}
	else {
		std::cout << *this << " cannot sign " << form << " because of low rank!" << std::endl;
	}
}

void			Bureaucrat::executeForm(Form const & form) {
	if (form.getStatus() == false) {
		std::cout << *this << " cannot execute " << form << " because isnt signed!" << std::endl;
	}
	else if (getGrade() <= form.getExecGrade()) {
		form.execute(*this);
		std::cout << *this << " executes " << form << std::endl;
	}
	else {
		std::cout << *this << " cannot execute " << form << " because of low grade!" << std::endl;
	}
}