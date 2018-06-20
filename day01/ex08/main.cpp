#include "Human.hpp"

int	main(void) {
	Human *assasin = new Human();
	assasin->action("meleeAttack", "Bob");
	assasin->action("rangedAttack", "Charley");
	assasin->action("intimidatingShout", "Ashley");
	delete assasin;
	return (0);
}