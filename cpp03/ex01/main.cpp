#include "ClapTrap.hpp"

int main(void)
{
	std::cout << "=== TEST 1: constructors (default / copy / with name) ===" << std::endl;
	ClapTrap	a;
	ClapTrap	b(a);
	ClapTrap	c("Peppino");
	std::cout << std::endl;

	std::cout << "=== TEST 2: normal attack / takeDamage / beRepaired ===" << std::endl;
	b.attack(c.getName());
	c.takeDamage(3);
	c.beRepaired(2);
	std::cout << std::endl;

	std::cout << "=== TEST 3: takeDamage with amount > remaining hit points (no underflow) ===" << std::endl;
	c.takeDamage(999);
	std::cout << std::endl;

	std::cout << "=== TEST 4: attack / beRepaired with 0 hit points ===" << std::endl;
	c.attack(b.getName());
	c.beRepaired(5);
	std::cout << std::endl;

	std::cout << "=== TEST 5: energy runs out, then attack fails too ===" << std::endl;
	ClapTrap	d("Energico");
	for (int i = 1; i <= 11; i++)
	{
		std::cout << "action n." << i << ": ";
		d.beRepaired(1);
	}
	d.attack("qualcuno");
	std::cout << std::endl;

	std::cout << "=== TEST 6: destructor called at end of a limited scope ===" << std::endl;
	{
		ClapTrap	e("Temporaneo");
		e.attack("bersaglio");
	}
	std::cout << "(e is now out of scope)" << std::endl << std::endl;

	return 0;
}