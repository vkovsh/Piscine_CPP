#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP
# include <iostream>
# include <cmath>

class	Fixed	{
	private:
		int					_fixedPointVal;

		//fraction bits number
		static const int	_fractionBits = 8;

	public:
		static int			getFractionBitsNb( void );
		int					getRawBits( void ) const;
		void				setRawBits( int const raw );

		//assign operator overloading
		void				operator = (const Fixed &cpy);

		//default constructor
		Fixed( void );

		//copy constructror
		Fixed( Fixed const &cpy );

		//int -> Fixed(_fractionBits) constructor
		Fixed( int const &nbr );

		//float -> Fixed(_fractionBits) constructor
		Fixed( float const &flt );

		~Fixed( void );

		//returns float representation
		float				toFloat( void ) const;

		//returns int representation
		int					toInt( void ) const;
};

//streaming operator overloading
std::ostream				&operator << (std::ostream &o, const Fixed &cpy);
#endif