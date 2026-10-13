#include "Brain.hpp"

Brain::Brain()
{
	std::cout << GREEN << "BRAIN DEFAULT CONSTRUCTOR CALLED" << RESET << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << GREEN << "BRAIN COPY CONSTRUCTOR CALLED" << RESET << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << GREEN << "BRAIN COPY ASSIGNMENT OPERATOR CALLED" << RESET << std::endl;

	if (this == &other)
		return *this;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	return *this;
}

Brain::~Brain()
{
	std::cout << GREEN << "BRAIN DESTRUCTOR CALLED" << RESET << std::endl;
}

std::string	Brain::getIdeas(unsigned int i) const
{
	if (i > 99)
	{
		std::cout << "The index must be max 99!";
		return "";
	}
	else
		return ideas[i];
}

void	Brain::setIdeas(const std::string &idea, const unsigned int i)
{
	if (i > 99)
	{
		std::cout << "The index must be max 99!" << std::endl;
		return ;
	}
	std::cout << "The idea number " << i << " was set in : " << idea << " !" << std::endl;
	ideas[i] = idea;
}
