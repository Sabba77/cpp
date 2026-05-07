#include <iostream>
#include <string>

int main() {
	// Variabile richiesta dal subject
	std::string str = "HI THIS IS BRAIN";

	// Puntatore: contiene l'indirizzo di str
	std::string *stringPTR = &str;

	// Reference: è un alias di str (non "contiene" un indirizzo separato)
	std::string &stringREF = str;

	// Indirizzi
	std::cout << "Address of str      : " << &str << std::endl;
	std::cout << "Address in stringPTR: " << stringPTR << std::endl;
	std::cout << "Address of stringREF: " << &stringREF << std::endl;

	std::cout << std::endl;

	// Valori
	std::cout << "Value of str        : " << str << std::endl;
	std::cout << "Value via stringPTR : " << *stringPTR << std::endl;
	std::cout << "Value via stringREF : " << stringREF << std::endl;

	return 0;
}
