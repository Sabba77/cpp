#include "AMateria.hpp"

Character::Character() : name("noName")
{
	std::cout << "CHARACTER DEFAULT CONSTRUCTOR CALLED!" << std::endl;
	for (int i = 0; i < 4; i++)
		materiaArray[i] = NULL;
}

Character::Character(const Character& other) : name(other.getName())
{
	std::cout << "CHARACTER COPY CONSTRUCTOR CALLED!" << std::endl;
	for (int i = 0; i < 4; i++)
		materiaArray[i] = NULL;
	for (int i = 0; i < 4; i++)
	{
		if (other.materiaArray[i])
			materiaArray[i] = other.materiaArray[i]->clone();
	}
}

Character::Character(const std::string& otherName) : name(otherName)
{
	std::cout << "CHARACTER CONSTRUCTOR WITH NAME CALLED!" << std::endl;
	for (int i = 0; i < 4; i++)
		materiaArray[i] = NULL;
}

Character& Character::operator=(const Character& other)
{
	std::cout << "CHARACTER COPY ASSIGNMENT OPERATOR CALLED!" << std::endl;
	if (this == &other)
		return *this;
	name = other.getName();
	for (int i = 0; i < 4; i++)
	{
		delete materiaArray[i];
		materiaArray[i] = NULL;
		if (other.materiaArray[i])
			materiaArray[i] = other.materiaArray[i]->clone();
	}
	return *this;
}

Character::~Character()
{
	std::cout << "CHARACTER DESTRUCTOR CALLED!" << std::endl;

	for (int i = 0; i < 4; i++)
		delete materiaArray[i];
}

const std::string&	Character::getName() const
{
	return name;
}

void	Character::equip(AMateria* m)
{
	int i = 0;
	if (m == NULL)
	{
		std::cout << "there is no materia to equip" << std::endl;
		return ;
	}
		for (i = 0; i < 4; i++)
	{
		if (!materiaArray[i])
		{
			materiaArray[i] = m;
			std::cout << "equipped materia: " << materiaArray[i]->getType() << ", at position n. " << i << "!" << std::endl;
			break;
		}
	}
	if (i >= 4)
		std::cout << "there is no space to add new materia!" << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx >= 4)
	{
		std::cout << "There are no slots for the index: " << idx << "!" << std::endl;
		return ;
	}
	if (idx >= 0 && idx < 4 && materiaArray[idx] != NULL)
	{
		materiaArray[idx] = 0;
		std::cout << "the slot number " << idx << ", has been unequipped." << std::endl;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && materiaArray[idx])
		materiaArray[idx]->use(target);
	else
		std::cout << this->name << "'s material array has no materia in that slot." << std::endl;
}
