#include "Base.hpp"

Base::Base(void){}

Base::Base(Base const & src){
	*this = src;
}
	
Base::~Base(void){}

Base &Base::operator=(Base const & cpy){
	*this = cpy;
	return *this;
}