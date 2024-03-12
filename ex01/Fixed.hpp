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
	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;	
};

std::ostream	&operator<<(std::ostream &os, Fixed const &fixed);