#include "Animal.hpp"

Brain::Brain()
{
	std::cout << "BRAIN DEFAULT CONSTRUCTOR CALLED" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "BRAIN COPY CONSTRUCTOR CALLED" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "BRAIN COPY ASSIGNMENT OPERATOR CALLED" << std::endl;

	if (this == &other)
		return *this;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	return *this;
}

Brain::~Brain()
{
	std::cout << "BRAIN DESTRUCTOR CALLED" << std::endl;
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