#include "Zombie.hpp"

// Questa funzione alloca un oggetto in HEAP (memoria dinamica).
// Lo zombie vive anche dopo la fine di questa funzione,
// quindi puoi usarlo "fuori" dallo scope.
Zombie* newZombie(std::string name) {
	return new Zombie(name);
}
