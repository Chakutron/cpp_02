#include <iostream>
#include <cmath>

class	Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed(const int i_nbr);
		Fixed(const float fp_nbr);
		~Fixed();
		Fixed	&operator=(const Fixed &fixed);
		int		getRawBits(void) const;
		void	setRawBits(int const nbr);
		float	toFloat(void) const;
		int		toInt(void) const;
		bool	operator>(Fixed const &fixed) const;
		bool	operator<(Fixed const &fixed) const;
		bool	operator>=(Fixed const &fixed) const;
		bool	operator<=(Fixed const &fixed) const;
		bool	operator==(Fixed const &fixed) const;
		bool	operator!=(Fixed const &fixed) const;
		Fixed	operator+(Fixed const &fixed);
		Fixed	operator-(Fixed const &fixed);
		Fixed	operator*(Fixed const &fixed);
		Fixed	operator/(Fixed const &fixed);
		Fixed	operator++();
		Fixed	operator++(int);
		Fixed	operator--();
		Fixed	operator--(int);
		static Fixed const &min(Fixed const &fixed1, Fixed const &fixed2);
		static Fixed const &max(Fixed const &fixed1, Fixed const &fixed2);
		static Fixed &min(Fixed &fixed1, Fixed &fixed2);
		static Fixed &max(Fixed &fixed1, Fixed &fixed2);
	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;	
};

std::ostream	&operator<<(std::ostream &os, Fixed const &fixed);