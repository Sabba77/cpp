#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#include <ctime>


int	main(void)
{
	srand(time(NULL)); // for rand()

	std::cout << BOLD_CYAN << "========== TEST 0: Main Test ==========" << RESET << std::endl;
	{
		try
		{
			Intern someRandomIntern;
			AForm* rrf;
			Bureaucrat a("peppe", 72);

			rrf = someRandomIntern.makeForm("RobotomyRequest", "Bender");

			std::cout << *rrf << std::endl;
			a.signForm(*rrf);
			std::cout << *rrf << std::endl;
			a.executeForm(*rrf);

			delete rrf;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}
}