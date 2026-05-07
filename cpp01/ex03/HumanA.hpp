#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

class HumanA {
	private:
		std::string _name;
		// HumanA è SEMPRE armato: reference obbligatoria, non può essere NULL.
		Weapon &_weapon;

	public:
		HumanA(std::string const &name, Weapon &weapon);
		~HumanA();

		void attack() const;
};

#endif
