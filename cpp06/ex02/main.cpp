#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main(void)
{
	srand(time(NULL));

	Base* p = generate();

	identify(p);

	identify(*p);

	delete p;
	return 0;
}