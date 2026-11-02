#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <ctime>

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
	std::cout << "A" << std::endl;
	(void)a;
  }
  catch (const std::exception& e)
  {
  }

  try
  {
    B& b = dynamic_cast<B&>(p);
    std::cout << "B" << std::endl;
	(void)b;
  }
  catch (const std::exception& e)
  {
  }

  try
  {
    C& c = dynamic_cast<C&>(p);
    std::cout << "C" << std::endl;
	(void)c;
  }
  catch (const std::exception& e)
  {
  }
}