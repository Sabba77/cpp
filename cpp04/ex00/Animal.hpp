#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class	Animal
{
protected:
	std::string	type;

public:
	Animal();
	Animal(const Animal& other);
	Animal(const std::string &otherType);

	Animal& operator=(const Animal &other);

	virtual ~Animal();

	std::string getType() const;
	virtual void	makeSound() const;

};


class	Cat : public Animal
{
public:
	Cat();
	Cat(const Cat &otherCat);

	Cat& operator=(const Cat& otherCat);
	~Cat();

	void	makeSound() const;
};

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