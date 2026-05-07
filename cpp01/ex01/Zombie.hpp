#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {
	private:
		// Il subject richiede un attributo string "name" (qui lo chiamiamo _name).
		std::string _name;

	public:
		// Serve un costruttore di default perché per creare un array con:
		//   new Zombie[N]
		// C++ costruisce N oggetti usando il costruttore di default.
		Zombie();

		// Costruttore comodo per creare uno zombie già nominato.
		Zombie(std::string const &name);

		// Distruttore: stampa un messaggio con il nome (debug richiesto dal subject).
		~Zombie();

		// Stampa: <name>: BraiiiiiiinnnzzzZ...
		void announce(void) const;

		// Per "inizializzare" gli zombie dell'horde dopo la new[]
		void setName(std::string const &name);
};

// Alloca N Zombie in UN'UNICA allocazione (heap) e li inizializza.
// Ritorna un puntatore al primo elemento dell'array.
// Nota: chi chiama deve fare delete[] sul puntatore ritornato.
Zombie* zombieHorde(int N, std::string name);

#endif
