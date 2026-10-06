#include "Zombie.hpp"

int main()
{
	// Caso 1: STACK allocation (vita limitata allo scope)
	std::cout << BLUE << "\n\n--- RANDOMCHUMP (STACK) ---" << RESET << std::endl;
	randomChump("StackZombieee");

	// Caso 2: HEAP allocation (vita controllata manualmente)
	std::cout << BLUE << "\n--- NEWZOMBIE (HEAP) ---" << RESET << std::endl;
	Zombie *z = newZombie("HeapZombieee");
	z->announce();

	delete z;

	std::cout << BOLD_BLINK << "\nDone.\n\n" << RESET << std::endl;
	return 0;
}
