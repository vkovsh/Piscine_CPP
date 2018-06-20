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
	std::string	func_names[3] = {"meleeAttack", "rangedAttack", "intimidatingShout"};
	for (int i = 0; i < 3; ++i) {
		if (action_name == func_names[i]) {
			attacks_func attack = attacks[i];
			(this->*attack)(target);
			break ;
		}
	}
}
		
	