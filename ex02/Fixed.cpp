#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int i_nbr)
{
	//std::cout << "Int constructor called" << std::endl;
	this->_rawBits = (i_nbr << Fixed::_fractionalBits);
}

Fixed::Fixed(const float fp_nbr)
{
	//std::cout << "Float constructor called" << std::endl;
	this->_rawBits = roundf(fp_nbr * (1 << Fixed::_fractionalBits));
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &fixed)
{
	//std::cout << "Copy assignment operator called" << std::endl;
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

bool	Fixed::operator>(Fixed const &fixed) const
{
	if (this->_rawBits > fixed.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<(Fixed const &fixed) const
{
	if (this->_rawBits < fixed.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(Fixed const &fixed) const
{
	if (this->_rawBits >= fixed.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(Fixed const &fixed) const
{
	if (this->_rawBits <= fixed.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(Fixed const &fixed) const
{
	if (this->_rawBits == fixed.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(Fixed const &fixed) const
{
	if (this->_rawBits != fixed.getRawBits())
		return (true);
	return (false);
}

Fixed	Fixed::operator+(Fixed const &fixed)
{
	this->_rawBits += fixed.getRawBits();
	return (*this);
}

Fixed	Fixed::operator-(Fixed const &fixed)
{
	this->_rawBits -= fixed.getRawBits();
	return (*this);
}

Fixed	Fixed::operator*(Fixed const &fixed)
{
	this->_rawBits = (this->toFloat() * fixed.toFloat()) * (1 << _fractionalBits);
	return (*this);
}

Fixed	Fixed::operator/(Fixed const &fixed)
{
	this->_rawBits = (this->toFloat() / fixed.toFloat()) * (1 << _fractionalBits);
	return (*this);
}

Fixed	Fixed::operator++()
{
	this->_rawBits++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	++(*this);
	return (tmp);
}

Fixed	Fixed::operator--()
{
	this->_rawBits--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	--(*this);
	return (tmp);
}

Fixed const	&Fixed::min(Fixed const &fixed1, Fixed const &fixed2)
{
	if (fixed1.getRawBits() > fixed2.getRawBits())
		return (fixed2);
	return (fixed1);
}

Fixed const	&Fixed::max(Fixed const &fixed1, Fixed const &fixed2)
{
	if (fixed1.getRawBits() < fixed2.getRawBits())
		return (fixed2);
	return (fixed1);
}

Fixed	&Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1.getRawBits() > fixed2.getRawBits())
		return (fixed2);
	return (fixed1);
}

Fixed	&Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1.getRawBits() < fixed2.getRawBits())
		return (fixed2);
	return (fixed1);
}