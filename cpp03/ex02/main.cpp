#include "FragTrap.hpp"

int main(void)
{
	// --- Test costruzione e distruzione ---
	FragTrap	a;
	FragTrap	b(a);
	FragTrap	c("Peppino");

	// --- Test attack normale ---
	c.attack(b.getName());
	b.takeDamage(c.getAttackDamage());
	b.beRepaired(10);

	// --- Test highFivesGuys ---
	a.highFivesGuys();

	// --- Test attack con 0 hitPoints ---
	{
		FragTrap dying("Morente");
		dying.takeDamage(100);
		dying.attack("qualcuno");
	}

	// --- Test attack con 0 energyPoints ---
	{
		FragTrap tired("Stanco");
		for (int i = 0; i < 100; i++)
			tired.attack("dummy");
		tired.attack("dummy");
	}

	return 0;
}