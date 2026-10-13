#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class	Cat : public Animal
{
public:
	Cat();
	Cat(const Cat &otherCat);

	Cat& operator=(const Cat& otherCat);
	~Cat();

	void	makeSound() const;
};

#endif