#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int i_nbr)
{
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = (i_nbr << Fixed::_fractionalBits);
}

Fixed::Fixed(const float fp_nbr)
{
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = roundf(fp_nbr * (1 << Fixed::_fractionalBits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(fixed.getRawBits());
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (_rawBits);
}

void	Fixed::setRawBits(int const nbr)
{
	this->_rawBits = nbr;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_rawBits / (float)(1 << Fixed::_fractionalBits));
}

int		Fixed::toInt(void) const
{
	return (this->_rawBits >> Fixed::_fractionalBits);
}

std::ostream	&operator<<(std::ostream &os, Fixed const &fixed)
{
	os << fixed.toFloat();
	return (os);
}