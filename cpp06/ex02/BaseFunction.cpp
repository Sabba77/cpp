#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base* generate(void)
{
	unsigned int	randomNumber;

	switch (randomNumber = rand() % 3)
	{
	case 0:
		return new A;
	case 1:
		return new B;
	case 2:
		return new C;
	default:
		break;
	}
	return NULL;
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << GREEN << "A" << RESET << std::endl;

	if (dynamic_cast<B*>(p) != NULL)
		std::cout << GREEN << "B" << RESET << std::endl;

	if (dynamic_cast<C*>(p) != NULL)
		std::cout << GREEN << "C" << RESET << std::endl;
}
void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << GREEN << "A" << RESET << std::endl;
		(void)a;
	}
	catch (...)
	{
	}

	try
	{
		B& b = dynamic_cast<B&>(p);
		std::cout << GREEN << "B" << RESET << std::endl;
		(void)b;
	}
	catch (...)
	{
	}

	try
	{
		C& c = dynamic_cast<C&>(p);
		std::cout << GREEN << "C" << RESET << std::endl;
		(void)c;
	}
	catch (...)
	{
	}
}