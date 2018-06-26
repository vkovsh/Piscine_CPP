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