#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MATERIASOURCE DEFAULT CONSTRUCTOR CALLED!" << std::endl;
	for (int i = 0; i < 4; i++)
		materiaSourceArray[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	std::cout << "MATERIASOURCE COPY CONSTRUCTOR CALLED!" << std::endl;
	for (int i = 0; i < 4; i++)
		materiaSourceArray[i] = NULL;
	for (int i = 0; i < 4; i++)
	{
		if (other.materiaSourceArray[i])
			materiaSourceArray[i] = other.materiaSourceArray[i]->clone();
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	std::cout << "MATERIASOURCE COPY ASSIGNMENT OPERATOR CALLED!" << std::endl;
	if (this == &other)
		return *this;
	for (int i = 0; i < 4; i++)
	{
		delete materiaSourceArray[i];
		materiaSourceArray[i] = NULL;
		if (other.materiaSourceArray[i])
			materiaSourceArray[i] = other.materiaSourceArray[i]->clone();
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MATERIASOURCE DESTRUCTOR CALLED!" << std::endl;

	for (int i = 0; i < 4; i++)
		delete materiaSourceArray[i];
}

void	MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!materiaSourceArray[i] && m)
		{
			materiaSourceArray[i] = m->clone();
			break ;
		}
	}
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (materiaSourceArray[i] && materiaSourceArray[i]->getType() == type)
			return (materiaSourceArray[i]->clone());
	}
	return NULL;
}