#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP
# include <iostream>

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

		//copy constructro
		Fixed( Fixed &cpy );

		~Fixed( void );

};

#endif