#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon {
	private:
		std::string _type;

	public:
		// Serve perché in main viene fatto: Weapon club = Weapon("...");
		Weapon(std::string const &type);
		~Weapon();

		// Ritorna una reference costante: non copia la stringa.
		std::string const &getType() const;
		void setType(std::string const &type);
};

#endif
