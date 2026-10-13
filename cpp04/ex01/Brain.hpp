#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BOLD_CYAN	"\033[1;36m"
#define RESET   "\033[0m"


class	Brain
{
private:
	std::string	ideas[100];

public:
	Brain();
	Brain(const Brain& other);

	Brain& operator=(const Brain& other);

	~Brain();

	std::string	getIdeas(unsigned int i) const;
	void	setIdeas(const std::string& idea, const unsigned int i);

};

#endif