#include <iostream>

class	Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		~Fixed();
		Fixed	&operator=(const Fixed &fixed);
		int		getRawBits(void) const;
		void	setRawBits(int const nbr);
	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;
};