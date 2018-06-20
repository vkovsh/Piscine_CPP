#include "Human.hpp"

int	main(void) {
	Human *assasin = new Human();
	assasin->action("0", "Bob");
	assasin->action("1", "Charley");
	assasin->action("2", "Ashley");
	delete assasin;
	return (0);
}