#include "Harl.hpp"

# include <iostream>
# include <string>

static int levelIndex(std::string const &level) {
	static const char *levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; ++i) {
		if (level == levels[i])
			return i;
	}
	return -1;
}

static void printHeader(char const *label) {
	std::cout << "[ " << label << " ]" << std::endl;
}

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <DEBUG|INFO|WARNING|ERROR>" << std::endl;
		return 1;
	}

	Harl harl;
	int idx = levelIndex(argv[1]);

	switch (idx) {
		case 0:
			printHeader("DEBUG");
			harl.complain("DEBUG");
			// fall through
		case 1:
			printHeader("INFO");
			harl.complain("INFO");
			// fall through
		case 2:
			printHeader("WARNING");
			harl.complain("WARNING");
			// fall through
		case 3:
			printHeader("ERROR");
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}

	return 0;
}
