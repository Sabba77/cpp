#include "Zombie.hpp"

// Questa funzione crea un oggetto in STACK (variabile locale).
// Appena la funzione termina, lo zombie viene distrutto automaticamente.
void randomChump(std::string name) {
	Zombie z(name);
	z.announce();
	// Qui non serve delete: z verrà distrutto da solo (RAII).
}
