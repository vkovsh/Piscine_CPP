#include "B.hpp"

B::B(void){}

B::B(B const & cpy): Base(cpy) {}

B::~B(void){}
	
B &B::operator=(B const & cpy) {
	*this = cpy;
	return *this;
}