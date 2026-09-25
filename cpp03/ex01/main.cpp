#include "ScavTrap.hpp"

int main(void)
{
	// --- Test costruzione e distruzione ---
	ScavTrap	a;
	ScavTrap	b(a);
	ScavTrap	c("Peppino");

	// --- Test attack normale ---
	c.attack(b.getName());
	b.takeDamage(c.getAttackDamage());
	b.beRepaired(10);

	// --- Test guardGate ---
	a.guardGate();

	// --- Test attack con 0 hitPoints ---
	{
		ScavTrap dying("Morente");
		dying.takeDamage(100); // lo porto a 0 hp
		dying.attack("qualcuno"); // deve stampare "is dead!"
	}

	// --- Test attack con 0 energyPoints ---
	{
		ScavTrap tired("Stanco");
		for (int i = 0; i < 50; i++)
			tired.attack("dummy"); // esaurisce i 50 energyPoints
		tired.attack("dummy"); // deve stampare "had no energy!"
	}

	return 0;
}