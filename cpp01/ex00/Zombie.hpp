#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {
	private:
		std::string _name;

	public:
		// Costruttore di default: crea uno zombie senza nome (utile per esempi/debug).
		Zombie();
		// Costruttore "comodo": crea e inizializza direttamente il nome.
		Zombie(std::string const &name);
		// Distruttore: stampa un messaggio per capire quando lo zombie viene distrutto.
		~Zombie();

		// Stampa: <name>: BraiiiiiiinnnzzzZ...
		void announce(void) const;

		// Setter del nome: utile se crei prima lo zombie e poi assegni il nome.
		void setName(std::string const &name);
};

// Crea uno Zombie in HEAP (con new) e restituisce il puntatore.
// Chi chiama questa funzione deve poi fare delete.
Zombie* newZombie(std::string name);

// Crea uno Zombie in STACK (variabile locale), lo fa annunciare e poi termina.
// La distruzione avviene automaticamente quando la funzione finisce.
void randomChump(std::string name);

#endif
