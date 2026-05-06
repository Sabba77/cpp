#include "Zombie.hpp"

# include <iostream>

int main() {
	// Caso 1: STACK allocation (vita limitata allo scope)
	std::cout << "--- randomChump (stack) ---" << std::endl;
	randomChump("StackZombie");

	// Caso 2: HEAP allocation (vita controllata manualmente)
	std::cout << "\n--- newZombie (heap) ---" << std::endl;
	Zombie *z = newZombie("HeapZombie");
	z->announce();

	// IMPORTANTE: se non fai delete, crei una memory leak.
	delete z;

	std::cout << "\nDone." << std::endl;
	return 0;
}
