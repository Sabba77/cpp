#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <stdint.h>
#include <string>
#include <iostream>

#define RED			"\033[31m"
#define GREEN		"\033[32m"
#define YELLOW		"\x1b[33m"
#define BOLD_CYAN	"\033[1;36m"
#define BLACK_GRAY	"\033[90m"
#define RESET		"\033[0m"

struct Data
{
	std::string	str;
	unsigned int value;
};


class	Serializer
{
private:
	Serializer();
	Serializer(const Serializer&);
	Serializer& operator=(const Serializer&);
	~Serializer();

public:
	static uintptr_t	serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

};

#endif