#include "Zombie.hpp"

// Requisito: "allocate N Zombie objects in a single allocation".
// In C++ questo si fa con: new Zombie[N]
Zombie* zombieHorde(int N, std::string name) {
	if (N <= 0)
		return 0;

	Zombie *horde = new Zombie[N];

	// Requisito: inizializzare ogni zombie con il nome passato.
	for (int i = 0; i < N; ++i) {
		horde[i].setName(name);
	}
	return horde;
}
