#include "HumanB.hpp"

# include <iostream>

HumanB::HumanB(std::string const &name) : _name(name), _weapon(0) {
	// _weapon parte NULL: HumanB non è per forza armato.
}

HumanB::~HumanB() {
}

void HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
}

void HumanB::attack() const {
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " attacks with their bare hands" << std::endl;
}
