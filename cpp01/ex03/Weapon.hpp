#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define	BLUE	"\033[1;36m"
#define BOLD_BLINK	"\033[1;5;31m"
#define RESET   "\033[0m"

class Weapon
{
	private:
		std::string _type;

	public:
		Weapon(std::string const &type);
		~Weapon();

		// Ritorna una reference costante: non copia la stringa.
		std::string const &getType() const;
		void setType(std::string const &type);
};

#endif
