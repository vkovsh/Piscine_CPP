#ifndef BRAIN_H
# define BRAIN_H
# include <iostream>
# include <sstream>

class	Brain	{
	private:
		int			_iq;
		std::string	_adress;

	public:
		Brain( int iq = 100 );
		~Brain( void );
		
		int	GetIq( void );
		std::string identify( void ) const;
};

#endif