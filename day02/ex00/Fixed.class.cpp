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

Fixed::Fixed( Fixed &cpy ) {
	*this = cpy;
	std::cout << "Copy constructor called" << std::endl;
}

void	Fixed::operator = (const Fixed &cpy) {
	this->setRawBits(cpy.getRawBits());
	std::cout << "Assignation operator called" << std::endl; 
}