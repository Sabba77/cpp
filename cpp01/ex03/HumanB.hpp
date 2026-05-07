#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

class HumanB {
	private:
		std::string _name;
		// HumanB può NON avere un'arma: puntatore, può essere NULL.
		Weapon *_weapon;

	public:
		HumanB(std::string const &name);
		~HumanB();

		void setWeapon(Weapon &weapon);
		void attack() const;
};

#endif
