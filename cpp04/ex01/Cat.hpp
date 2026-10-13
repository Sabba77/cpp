#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal
{
private:
	Brain* catBrain;

public:
	Cat();
	Cat(const Cat &otherCat);

	Cat& operator=(const Cat& otherCat);
	~Cat();

	Brain*	getBrain() const;
	void	makeSound() const;
};

#endif