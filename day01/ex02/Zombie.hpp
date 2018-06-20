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

		void		announce( void );

		Zombie( void );
		Zombie( std::string name );
		Zombie( std::string name, std::string type);

		~Zombie( void );
};

#endif