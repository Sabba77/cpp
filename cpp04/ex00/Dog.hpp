#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class	Dog : public Animal
{
public:
	Dog();
	Dog(const Dog &otherDog);

	Dog& operator=(const Dog& otherDog);
	~Dog();

	void	makeSound() const;
};

#endif