#include "HumanA.hpp"
# include "HumanB.hpp"
# include "Weapon.hpp"

int main()
{
	{
		Weapon club = Weapon("sword");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("gun");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}
