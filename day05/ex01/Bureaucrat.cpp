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

void			Bureaucrat::promote() {
	if (_rank > 1) {
		--_rank;
	}
	else {
		throw _h;
	}
}

void			Bureaucrat::demote() {
	if (_rank < 150) {
		++_rank;
	}
	else {
		throw _l;
	}
}

void			Bureaucrat::signForm(Form & form) const {
	if (form.getStatus() == true) {
		std::cout << this << " cannot sign " << form << " because it's already signed!";
	}
	else if (_rank <= form.getGrade()) {
		form.beSigned(*this);
		std::cout << *this << " signs " << form;
	}
	else {
		std::cout << *this << " cannot sign " << form << " because of low rank!";
	}
}