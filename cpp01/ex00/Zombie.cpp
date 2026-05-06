#include "Zombie.hpp"

# include <iostream>

Zombie::Zombie() : _name("(unnamed)") {
	// Nota: questo costruttore non è richiesto esplicitamente dal subject,
	// ma è utile per comprendere e debuggare.
}

Zombie::Zombie(std::string const &name) : _name(name) {
}

Zombie::~Zombie() {
	// Il subject chiede SOLO che venga stampato un messaggio con il nome.
	std::cout << "Zombie " << _name << " destroyed" << std::endl;
}

void Zombie::setName(std::string const &name) {
	_name = name;
}

void Zombie::announce(void) const {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
