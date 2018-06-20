#ifndef HUMAN_H
# define HUMAN_H
# include <iostream>
# include "Brain.hpp"

class	Human	{
	private:
		const Brain	_brain;
		std::string	_name;

	public:
		Human( std::string name = "Jack" );
		~Human ( void );
		std::string	identify() const;
		const Brain	&getBrain( void );
};

#endif