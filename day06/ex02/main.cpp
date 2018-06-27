#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <time.h>
#include <iostream>
#include <cstdlib>

Base	*generate(void)
{
	int ran = (rand() % 3);

	if (ran == 0)
		return new A();
	else if (ran == 1)
		return new B();
	else if (ran == 2)
		return new C();
	return (NULL);
}

void	identify_from_pointer(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "C" << std::endl;
}

void	identify_from_reference(Base &p)
{
	if (dynamic_cast<A *>(&p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(&p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(&p) != NULL)
		std::cout << "C" << std::endl;			
}

int	main(void)
{
	Base	*p[10];

	srand(time(NULL));
	for (int i = 0; i < 10; ++i) {
		p[i] = generate();
		identify_from_pointer(p[i]);
		identify_from_reference(*p[i]);
		delete p[i];
	}
	return (0);
}