#include <iostream>
#include <string>

#define BACK_YELLOW	"\x1b[43m"
#define BACK_GREEN	"\x1b[42m"
#define BLACK	"\x1b[30m"
#define RESET	"\x1b[0m"

int main() {
	// Variabile richiesta dal subject
	std::string str = "HI THIS IS BRAIN";

	// Puntatore: contiene l'indirizzo di str
	std::string *stringPTR = &str;

	// Reference: è un alias di str (non "contiene" un indirizzo separato)
	std::string &stringREF = str;

	// Indirizzi
	std::cout << BACK_YELLOW << BLACK << "Address of str      : " << &str << std::endl;
	std::cout << "Address in stringPTR: " << stringPTR << std::endl;
	std::cout << "Address of stringREF: " << &stringREF << RESET << std::endl;

	std::cout << std::endl;

	// Valori
	std::cout << BACK_GREEN << BLACK << "Value of str        : " << str << std::endl;
	std::cout << "Value via stringPTR : " << *stringPTR << std::endl;
	std::cout << "Value via stringREF : " << stringREF << RESET << std::endl;

	return 0;
}
