#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BOLD_CYAN	"\033[1;36m"
#define RESET   "\033[0m"

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

#endif