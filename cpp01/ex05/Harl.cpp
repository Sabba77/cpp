#include "Harl.hpp"

# include <iostream>

Harl::Harl() {
}

Harl::~Harl() {
}

void Harl::debug(void) {
	std::cout
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
		<< std::endl;
}

void Harl::info(void) {
	std::cout
		<< "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
		<< std::endl;
}

void Harl::warning(void) {
	std::cout
		<< "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month."
		<< std::endl;
}

void Harl::error(void) {
	std::cout
		<< "This is unacceptable! I want to speak to the manager now."
		<< std::endl;
}

// Obiettivo del subject: evitare una "foresta" di if/else.
// Soluzione: tabella di dispatch con puntatori a funzioni membro.
void Harl::complain(std::string level) {
	typedef void (Harl::*t_action)(void);

	struct Entry {
		const char *level;
		t_action action;
	};

	static const Entry table[] = {
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error}
	};

	for (int i = 0; i < 4; ++i) {
		if (level == table[i].level) {
			(this->*table[i].action)();
			return;
		}
	}

	// Input non valido: comportamento "relevant" e semplice.
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
