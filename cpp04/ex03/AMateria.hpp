#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include <iostream>

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

class ICharacter
{
public:
	virtual ~ICharacter() {}
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

class Character : public ICharacter
{
private:
	std::string	name;
	AMateria*	materiaArray[4];

public:
	Character();
	Character(const Character& other);
	Character(const std::string& otherName);

	Character& operator=(const Character& other);

	std::string const& getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

	~Character();
};


class	Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice& other);
	Ice& operator=(const Ice&);

	~Ice();

	AMateria* clone() const;
	void	use(ICharacter& target);
};

class	Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure& other);
	Cure& operator=(const Cure&);

	~Cure();

	AMateria* clone() const;
	void	use(ICharacter& target);
};


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