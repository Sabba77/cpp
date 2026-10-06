#include "Zombie.hpp"

// Questa funzione alloca un oggetto in HEAP (memoria dinamica).
Zombie* newZombie(std::string name)
{
	return new Zombie(name);
}
