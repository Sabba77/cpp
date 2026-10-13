#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AMateria.hpp"

class AMateria;

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

#endif