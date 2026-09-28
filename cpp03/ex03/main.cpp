#include "DiamondTrap.hpp"

int main(void)
{
	// --- Test costruzione e distruzione ---
	DiamondTrap	a;
	DiamondTrap	b(a);
	DiamondTrap	c("Peppino");

	// --- Test whoAmI ---
	a.whoAmI();
	c.whoAmI();

	// --- Test attack normale (deve usare la versione di ScavTrap) ---
	c.attack(b.getName());
	b.takeDamage(c.getAttackDamage());
	b.beRepaired(10);

	// --- Test funzioni speciali ereditate da entrambi i parent ---
	a.guardGate();
	a.highFivesGuys();

	// --- Test attack con 0 hitPoints ---
	{
		DiamondTrap dying("Morente");
		dying.takeDamage(100);
		dying.attack("qualcuno");
	}

	// --- Test attack con 0 energyPoints (DiamondTrap usa 50 energy, da ScavTrap) ---
	{
		DiamondTrap tired("Stanco");
		for (int i = 0; i < 50; i++)
			tired.attack("dummy");
		tired.attack("dummy");
	}

	return 0;
}