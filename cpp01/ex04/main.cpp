#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

// Sostituisce tutte le occorrenze di s1 con s2 SENZA usare std::string::replace.
static std::string replaceAll(std::string const &input,
					 std::string const &s1,
					 std::string const &s2) {
	std::string output;
	std::string::size_type pos = 0;

	while (true) {
		std::string::size_type found = input.find(s1, pos);
		if (found == std::string::npos) {
			// Appendo il "resto" della stringa e termino.
			output.append(input, pos, std::string::npos);
			break;
		}
		// Appendo la parte prima del match, poi la sostituzione.
		output.append(input, pos, found - pos);
		output += s2;
		pos = found + s1.size();
	}
	return output;
}

static bool readFile(std::string const &filename, std::string &outContent) {
	std::ifstream in(filename.c_str(), std::ios::in | std::ios::binary);
	if (!in)
		return false;

	outContent.assign((std::istreambuf_iterator<char>(in)),
					  std::istreambuf_iterator<char>());
	return true;
}

static bool writeFile(std::string const &filename, std::string const &content) {
	std::ofstream out(filename.c_str(), std::ios::out | std::ios::binary);
	if (!out)
		return false;
	out << content;
	return (bool)out;
}

int main(int argc, char **argv) {
	// Uso: ./sed_is_for_losers <filename> <s1> <s2>
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string const filename = argv[1];
	std::string const s1 = argv[2];
	std::string const s2 = argv[3];

	// Caso limite: se s1 è vuota, la "ricerca" matcherebbe ovunque (loop infinito).
	if (s1.empty()) {
		std::cerr << "Error: s1 must not be empty" << std::endl;
		return 1;
	}

	std::string content;
	if (!readFile(filename, content)) {
		std::cerr << "Error: cannot open input file: " << filename << std::endl;
		return 1;
	}

	std::string const replaced = replaceAll(content, s1, s2);
	std::string const outFile = filename + ".replace";

	if (!writeFile(outFile, replaced)) {
		std::cerr << "Error: cannot write output file: " << outFile << std::endl;
		return 1;
	}

	return 0;
}
