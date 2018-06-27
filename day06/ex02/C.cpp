#include "C.hpp"

C::C(void){}

C::C(C const & cpy): Base(cpy) {}

C::~C(void){}
	
C &C::operator=(C const & cpy) {
	*this = cpy;
	return *this;
}