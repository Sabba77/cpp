#include "Zombie.hpp"

# include <iostream>

// Funzione di test: Stampa l'annuncio di ogni elemento dell'array.
static void announceHorde(Zombie* horde, int N)
{
	for (int i = 0; i < N; ++i)
	{
		std::cout << BLUE << "[" << i << "] " << RESET;
		horde[i].announce();
	}
}

int main()
{
	int const N = 5;

	std::cout << BLUE << "CREATING HORDE OF " << N << " ZOMBIES..." << RESET << std::endl;
	Zombie *horde = zombieHorde(N, "HordeZombieee");

	if (!horde)
	{
		std::cout << RED << "zombieHorde returned NULL" << RESET << std::endl;
		return 1;
	}
	announceHorde(horde, N);

	delete[] horde;

	std::cout << BLUE << "TEST EXTRA: N <= 0" << RESET << std::endl;
	Zombie *empty = zombieHorde(0, "Nobody");
	if (empty == 0)
		std::cout << GREEN << "OK: N=0 returns NULL" << RESET << std::endl;

	return 0;
}
