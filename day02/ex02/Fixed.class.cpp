#include "Fixed.class.hpp"

int		Fixed::getFractionBitsNb( void ) {
	return (Fixed::_fractionBits);
}

int		Fixed::getRawBits( void ) const {
	return (this->_fixedPointVal);
}

void	Fixed::setRawBits( int const raw ) {
	this->_fixedPointVal = raw;
}

Fixed::Fixed( void ): _fixedPointVal(0) {}

Fixed::~Fixed( void ) {}

Fixed::Fixed( Fixed const &cpy ) {
	*this = cpy;
}

void	Fixed::operator = (const Fixed &cpy) {
	this->_fixedPointVal = cpy._fixedPointVal;
}

Fixed::Fixed( int const &nbr ): _fixedPointVal(nbr << Fixed::_fractionBits) {}

Fixed::Fixed( float const &flt ): _fixedPointVal(roundf(flt * (1 << Fixed::_fractionBits))) {}

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

Fixed			&Fixed::min(Fixed &a, Fixed &b) {
	return ((a.getRawBits() < b.getRawBits()) ? a : b);
}

Fixed const		&Fixed::min(Fixed const &a, Fixed const &b) {
	return ((a.getRawBits() < b.getRawBits()) ? a : b);
}

Fixed			&Fixed::max(Fixed &a, Fixed &b) {
	return ((a.getRawBits() > b.getRawBits()) ? a : b);
}

Fixed const		&Fixed::max(Fixed const &a, Fixed const &b) {
	return ((a.getRawBits() > b.getRawBits()) ? a : b);
}

bool			Fixed::operator > (const Fixed &cpy) {
	return (this->getRawBits() > cpy.getRawBits());
}

bool			Fixed::operator < (const Fixed &cpy) {
	return (this->getRawBits() < cpy.getRawBits());
}

bool			Fixed::operator >= (const Fixed &cpy) {
	return (this->getRawBits() >= cpy.getRawBits());
}

bool			Fixed::operator <= (const Fixed &cpy) {
	return (this->getRawBits() >= cpy.getRawBits());
}

bool			Fixed::operator == (const Fixed &cpy) {
	return (this->getRawBits() == cpy.getRawBits());
}

bool			Fixed::operator != (const Fixed &cpy) {
	return (!(*this == cpy));
}

Fixed			Fixed::operator + (const Fixed &cpy) {
	Fixed	dst = Fixed();
	dst.setRawBits(this->getRawBits() + cpy.getRawBits());
	return (dst);
}

Fixed			Fixed::operator - (const Fixed &cpy) {
	Fixed	dst = Fixed();
	dst.setRawBits(this->getRawBits() - cpy.getRawBits());
	return (dst);
}

Fixed			Fixed::operator * (const Fixed &cpy) {
	Fixed	dst = Fixed();
	dst.setRawBits(this->getRawBits() * cpy.getRawBits());
	return (dst);
}

Fixed			Fixed::operator / (const Fixed &cpy) {
	Fixed	dst = Fixed();
	dst.setRawBits(this->getRawBits() / cpy.getRawBits());
	return (dst);
}

Fixed			&Fixed::operator++(void) {
	if (this->getRawBits() == 0 || ((this->getRawBits()) >> Fixed::getFractionBitsNb()) >= 0) {
		this->setRawBits(this->getRawBits() + 1);
	}
	return (*this);
}

Fixed			Fixed::operator++(int) {
	Fixed	temp = *this;
	++(*this);
	return (temp);
}

Fixed			&Fixed::operator--(void) {
	if (this->getRawBits() == 0 || ((this->_fixedPointVal) >> Fixed::getFractionBitsNb()) >= 0) {
		this->setRawBits(this->getRawBits() - 1);
	}
	//float nbr = (float)(this->getRawBits());
	///nbr /= (1 << Fixed::getFractionBitsNb());
	//nbr -=  
	return (*this);
}

Fixed			Fixed::operator--(int) {
	Fixed	temp = *this;
	--(*this);
	return (temp);
}