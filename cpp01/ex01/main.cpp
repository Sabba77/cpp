#include "Zombie.hpp"

# include <iostream>

static void announceHorde(Zombie *horde, int N) {
	// Funzione di test (richiesta: "Implement your own tests").
	// Stampa l'annuncio di ogni elemento dell'array.
	for (int i = 0; i < N; ++i) {
		std::cout << "[" << i << "] ";
		horde[i].announce();
	}
}

int main() {
	int const N = 5;

	std::cout << "Creating horde of " << N << " zombies..." << std::endl;
	Zombie *horde = zombieHorde(N, "HordeZombie");

	if (!horde) {
		std::cout << "zombieHorde returned NULL" << std::endl;
		return 1;
	}

	announceHorde(horde, N);

	// IMPORTANTISSIMO: avendo usato new Zombie[N], devi usare delete[].
	delete[] horde;

	// Test extra robustezza: N <= 0
	Zombie *empty = zombieHorde(0, "Nobody");
	if (empty == 0)
		std::cout << "OK: N=0 returns NULL" << std::endl;

	return 0;
}
