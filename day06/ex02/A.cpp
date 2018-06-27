#include "A.hpp"

A::A(void){}

A::A(A const & cpy): Base(cpy) {}

A::~A(void){}
	
A &A::operator=(A const & cpy) {
	*this = cpy;
	return *this;
}