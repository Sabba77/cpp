#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal
{
private:
	Brain* dogBrain;

public:
	Dog();
	Dog(const Dog &otherDog);

	Dog& operator=(const Dog& otherDog);
	~Dog();

	Brain*	getBrain() const;
	void	makeSound() const;
};

#endif