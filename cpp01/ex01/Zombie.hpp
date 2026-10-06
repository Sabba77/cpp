#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

#define RED     "\033[31m"
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

		void announce(void) const;
		void setName(std::string const &name);
};

// Alloca N Zombie in UN'UNICA allocazione (heap) e li inizializza.
// Ritorna un puntatore al primo elemento dell'array.
// Nota: chi chiama deve fare delete[] sul puntatore ritornato.
Zombie* zombieHorde(int N, std::string name);

#endif
