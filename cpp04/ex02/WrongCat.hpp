#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(const WrongCat &otherWrongCat);

	WrongCat& operator=(const WrongCat& otherWrongCat);
	~WrongCat();

	void	makeSound() const;
};

#endif