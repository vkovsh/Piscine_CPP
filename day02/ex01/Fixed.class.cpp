#include "Fixed.class.hpp"

int		Fixed::getFractionBitsNb( void ) {
	std::cout << "getFractionBitsNb member function called" << std::endl;
	return (Fixed::_fractionBits);
}

int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointVal);
}

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointVal = raw;
}

Fixed::Fixed( void ): _fixedPointVal(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( Fixed const &cpy ) {
	*this = cpy;
	std::cout << "Copy constructor called" << std::endl;
}

void	Fixed::operator = (const Fixed &cpy) {
	this->_fixedPointVal = cpy._fixedPointVal;
	std::cout << "Assignation operator called" << std::endl; 
}

Fixed::Fixed( int const &nbr ): _fixedPointVal(nbr << Fixed::_fractionBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( float const &flt ): _fixedPointVal(roundf(flt * (1 << Fixed::_fractionBits))) {
	std::cout << "Float constructor called" << std::endl;
}

float	Fixed::toFloat( void ) const {
	float result = (float)(this->_fixedPointVal);
	result /= (1 << Fixed::_fractionBits);
	return (result);
}

int		Fixed::toInt( void ) const {
	return ((this->_fixedPointVal) >> Fixed::_fractionBits);
}

std::ostream	&operator << (std::ostream &o, const Fixed &cpy) {
	o << cpy.toFloat();
	return o;
}