#include "Harl.hpp"

# include <iostream>

int main() {
	Harl harl;

	// Test richiesti: mostra che Harl si lamenta per vari livelli.
	std::cout << "--- DEBUG ---" << std::endl;
	harl.complain("DEBUG");

	std::cout << "\n--- INFO ---" << std::endl;
	harl.complain("INFO");

	std::cout << "\n--- WARNING ---" << std::endl;
	harl.complain("WARNING");

	std::cout << "\n--- ERROR ---" << std::endl;
	harl.complain("ERROR");

	// Caso extra: livello non riconosciuto
	std::cout << "\n--- UNKNOWN ---" << std::endl;
	harl.complain("BLAH");

	return 0;
}
