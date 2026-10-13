#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include <iostream>

#include "Character.hpp"

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BOLD_CYAN	"\033[1;36m"
#define RESET   "\033[0m"

class ICharacter;

class AMateria
{
protected:
	const std::string	type;

public:
	AMateria();
	AMateria(AMateria const& other);
	AMateria(std::string const& type);

	AMateria& operator=(const AMateria&);

	std::string const& getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

	virtual ~AMateria();

};

#endif