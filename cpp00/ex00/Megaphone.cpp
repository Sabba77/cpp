#include <iostream>
#include <string>
#include <cctype>

static std::string toUpperCase(const std::string &s)
{
	std::string out = s;
	unsigned char c;

	for (std::string::size_type i = 0; i < out.size(); i++)
	{
		c = static_cast<unsigned char>(out[i]);
		out[i] = static_cast<char>(std::toupper(c));
	}
	return out;
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i < ac; i++)
	{
		std::cout << toUpperCase(av[i]);
		if (i + 1 < ac)
			std::cout << " ";
	}
	std::cout << std::endl;
	return 0;
}