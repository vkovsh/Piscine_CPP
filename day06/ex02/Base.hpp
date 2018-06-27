#ifndef BASE_H
# define BASE_H

class	Base {
	public:
		Base(void);
		Base(Base const & cpy);
		virtual ~Base(void);
	
		Base &operator=(Base const & cpy);
};

#endif