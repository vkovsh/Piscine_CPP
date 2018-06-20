#include "Human.hpp"

void	Human::meleeAttack(std::string const & target) {
	std::cout << "Melee attack on " << target << std::endl;
}

void	Human::rangedAttack(std::string const & target) {
	std::cout << "Ranged attack on " << target << std::endl;
}

void	Human::intimidatingShout(std::string const & target) {
	std::cout << "Intimidating shout on " << target << std::endl;
}

void	Human::action(std::string const & action_name, std::string const & target) {
	typedef void (Human::*attacks_func)(std::string const &);
	attacks_func attacks[3] = {&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};
	attacks_func attack = attacks[action_name[0] - '0'];
	(this->*attack)(target);
}
		
	