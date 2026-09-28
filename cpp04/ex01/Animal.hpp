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


class	Brain
{
private:
	std::string	ideas[100];

public:
	Brain();
	Brain(const Brain& other);

	Brain& operator=(const Brain& other);

	~Brain();

	std::string	getIdeas(unsigned int i) const;
	void	setIdeas(const std::string& idea, const unsigned int i);

};


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