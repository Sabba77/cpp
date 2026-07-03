#include "Zombie.hpp"

# include <iostream>

int main() {
	// Caso 1: STACK allocation (vita limitata allo scope)
	std::cout << BLUE << "--- randomChump (stack) ---" << RESET << std::endl;
	randomChump("StackZombieee");

	// Caso 2: HEAP allocation (vita controllata manualmente)
	std::cout << BLUE << "\n--- newZombie (heap) ---" << RESET << std::endl;
	Zombie *z = newZombie("HeapZombieee");
	z->announce();

	// IMPORTANTE: se non fai delete, crei una memory leak.
	delete z;

	std::cout << "\nDone." << std::endl;
	return 0;
}
