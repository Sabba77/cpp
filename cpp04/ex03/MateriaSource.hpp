#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "AMateria.hpp"

class	IMateriaSource
{
public:
	virtual ~IMateriaSource() {};
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const& type) = 0;
};

class	MateriaSource : public IMateriaSource
{
private:
	AMateria*	materiaSourceArray[4];

public:
	MateriaSource();
	MateriaSource(const MateriaSource& other);
	MateriaSource& operator=(const MateriaSource& other);

	void learnMateria(AMateria* m);
	AMateria* createMateria(std::string const& type);

	~MateriaSource();
};

#endif