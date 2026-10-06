#include "Harl.hpp"

# include <iostream>

int main()
{
	Harl harl;

	// Test richiesti: mostra che Harl si lamenta per vari livelli.
	std::cout << BLUE << "--- DEBUG ---" << RESET << std::endl;
	harl.complain("DEBUG");

	std::cout << BLUE << "\n--- INFO ---" << RESET << std::endl;
	harl.complain("INFO");

	std::cout << BLUE << "\n--- WARNING ---" << RESET << std::endl;
	harl.complain("WARNING");

	std::cout << BLUE << "\n--- ERROR ---" << RESET << std::endl;
	harl.complain("ERROR");

	// Caso extra: livello non riconosciuto
	std::cout << BLUE << "\n--- UNKNOWN ---" << RESET << std::endl;
	harl.complain("BLAH");

	return 0;
}
