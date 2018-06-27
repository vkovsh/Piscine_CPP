#ifndef C_H
# define C_H
# include "Base.hpp"

class	C: public Base {
	public:
		C(void);
		C(C const & cpy);
		~C(void);
};

#endif