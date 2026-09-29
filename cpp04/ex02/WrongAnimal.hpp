#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class	WrongAnimal
{
protected:
	std::string	type;

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal(const std::string &otherType);

	WrongAnimal& operator=(const WrongAnimal &other);

	virtual ~WrongAnimal();

	std::string getType() const;
	void	makeSound() const;

};


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