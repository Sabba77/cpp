#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

#define RED     "\033[31;43m"
#define GREEN   "\033[32m"
#define	BLUE	"\033[1;36m"
#define BOLD_BLINK	"\033[1;5;31m"
#define RESET   "\033[0m"

class Zombie
{
	private:
		std::string _name;

	public:
		Zombie();
		Zombie(std::string const &name);
		~Zombie();

		// Stampa: <name>: BraiiiiiiinnnzzzZ...
		void announce(void) const;

		// Setter del nome: utile se crei prima lo zombie e poi assegni il nome.
		void setName(std::string const &name);
};

// Crea uno Zombie in HEAP (con new) e restituisce il puntatore.
Zombie* newZombie(std::string name);

// Crea uno Zombie in STACK (variabile locale), lo fa annunciare e poi termina.
void randomChump(std::string name);

#endif
