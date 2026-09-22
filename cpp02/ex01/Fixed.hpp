#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"

class Fixed
{
	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;

	public:
		Fixed();

		Fixed(const Fixed &other);

		Fixed(const int n);
		Fixed(const float n);

		Fixed&	operator=(const Fixed &other);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;

		~Fixed();
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif