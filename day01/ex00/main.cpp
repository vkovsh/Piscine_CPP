#include "Pony.hpp"

void	ponyOnTheHeap( std::string name ) {
	Pony *heap_pony = new Pony(name);
	delete heap_pony;
}

void	ponyOnTheStack( std::string name ) {
	Pony stack_pony = Pony(name);
}

int	main ( void ) {
	std::cout << "Allocation pony in the heap" << std::endl; 
	ponyOnTheHeap("Jane");
	std::cout << "Allocation pony in the stack" << std::endl;
	ponyOnTheStack("Mary");
	return (0);
}