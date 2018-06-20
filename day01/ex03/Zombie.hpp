#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <iostream>

class	Zombie {
	private:
		std::string	_name;
		std::string	_type;
		static const int _nameCount = 20;
		static std::string _names[Zombie::_nameCount];

	public:
		std::string	GetName( void );
		std::string	GetType( void );
		static std::string GetNameFromList( int index );
		static int	GetNameCount( void );

		void		announce( void );

		Zombie( std::string name = "Unknown",
				std::string type = "Infected");

		~Zombie( void );
};

#endif