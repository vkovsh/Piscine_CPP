#ifndef PONY_HPP
# define PONY_HPP
# include <iostream>

class Pony {
	private:
		std::string	_name;
		std::string	_color;
	
	public:
		std::string	GetName( void );
		std::string	GetColor( void );
		Pony( std::string name );
	
	Pony( void );
	~Pony( void );
};

#endif