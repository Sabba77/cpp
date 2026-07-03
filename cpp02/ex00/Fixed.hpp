#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

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
		Fixed&	operator=(const Fixed &other);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		~Fixed();
};

#endif