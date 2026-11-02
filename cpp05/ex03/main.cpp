#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#include <cstdlib>
#include <cstddef>
#include <ctime>

#define ALL_TESTS 7

static void	test0(void)
{
	std::cout << BOLD_CYAN << "========== TEST 0: Main Test ==========" << RESET << std::endl;
	try
	{
		Intern		someRandomIntern;
		AForm*		rrf;
		Bureaucrat	a("peppe", 72);

		rrf = someRandomIntern.makeForm("RobotomyRequest", "Bender");
		if (!rrf)
			return;

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

static void	test1(void)
{
	std::cout << BOLD_CYAN << "========== TEST 1: all possible form names ==========" << RESET << std::endl;

	Bureaucrat	boss("peppe", 5);
	Intern		someRandomIntern;
	AForm*		f = NULL;

	std::string	arrayForm[] = {
		"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm",
		"ShrubberyCreation", "RobotomyRequest", "PresidentialPardon",
		"shrubbery creation", "robotomy request", "presidential pardon" };
	const size_t	size = sizeof(arrayForm) / sizeof(arrayForm[0]);

	for (size_t i = 0; i < size; i++)
	{
		std::cout << BOLD_CYAN << "\n" << i + 1 << ") make and use form:" << RESET << std::endl;
		f = someRandomIntern.makeForm(arrayForm[i], "PepeTarg");
		if (!f)
			continue;
		std::cout << *f << std::endl;
		boss.signForm(*f);
		boss.executeForm(*f);
		std::cout << *f << std::endl;
		delete f;
	}
}

static void	test2(void)
{
	std::cout << BOLD_CYAN << "========== TEST 2: wrong names ==========" << RESET << std::endl;

	Intern		someRandomIntern;
	AForm*		f = NULL;

	std::string	arrayForm[] = {
		"Shrubbery CreationForm", "RobotomyRequXestForm", "PresidentialPardonForm ",
		"shrubberycreation", "Robotomy Request", "Presidential",
		"shrubbery", "PizzaForm", "" };
	const size_t	size = sizeof(arrayForm) / sizeof(arrayForm[0]);

	for (size_t i = 0; i < size; i++)
	{
		std::cout << BOLD_CYAN << "\n" << i + 1 << ") make and use form:" << RESET << std::endl;
		f = someRandomIntern.makeForm(arrayForm[i], "PepeTarg");
		if (!f)
			continue;
		std::cout << *f << std::endl;
		delete f;
	}
}

static void	test3(void)
{
	std::cout << BOLD_CYAN << "========== TEST 3: target = \"\" ==========" << RESET << std::endl;

	Intern	someRandomIntern;
	AForm*	f = someRandomIntern.makeForm("RobotomyRequestForm", "");

	if (!f)
		return;
	std::cout << *f << std::endl;
	delete f;
}

static void	test4(void)
{
	std::cout << BOLD_CYAN << "========== TEST 4: Intern class OCF ==========" << RESET << std::endl;

	Intern	a;
	Intern	b(a);
	Intern	c;

	c = b;
}

static void	test5(void)
{
	std::cout << BOLD_CYAN << "========== TEST 5: multiple AForm with same Intern ==========" << RESET << std::endl;

	Intern	sameIntern;
	std::cout << "Intern Address --> " << &sameIntern << std::endl;

	AForm*	ShCr = sameIntern.makeForm("ShrubberyCreation", "ShBossTarg");
	AForm*	RoRe = sameIntern.makeForm("RobotomyRequest", "RoBossTarg");
	AForm*	PrPa = sameIntern.makeForm("PresidentialPardon", "PrBossTarg");

	if (!ShCr || !RoRe || !PrPa)
	{
		std::cout << RED << "Unexpected NULL form" << RESET << std::endl;
		delete ShCr;
		delete RoRe;
		delete PrPa;
		return;
	}

	std::cout << *ShCr << std::endl;
	std::cout << *RoRe << std::endl;
	std::cout << *PrPa << std::endl;

	std::cout << "\nForm Address (must be different) : " << std::endl;
	std::cout << ShCr << std::endl;
	std::cout << RoRe << std::endl;
	std::cout << PrPa << std::endl;

	std::cout << "\nIntern Address --> " << &sameIntern << std::endl;

	delete ShCr;
	delete RoRe;
	delete PrPa;
}

int	main(void)
{
	srand(time(NULL)); // for rand()

	void	(*tests[])(void) = { test0, test1, test2, test3, test4, test5 };
	const int	n = sizeof(tests) / sizeof(tests[0]);
	int			choice = -1;

	std::cout << BOLD_CYAN << "0) main test" << std::endl
		<< "1) all valid names" << std::endl
		<< "2) wrong names" << std::endl
		<< "3) empty target" << std::endl
		<< "4) Intern OCF" << std::endl
		<< "5) multiple forms, same Intern" << std::endl << ALL_TESTS
		<< ") all tests" << std::endl
		<< "Choose: " << RESET;

	if (!(std::cin >> choice))
	{
		std::cout << RED << "\nInvalid input" << RESET << std::endl;
		return 1;
	}
	std::cout << std::endl;

	if (choice == ALL_TESTS)
	{
		for (int i = 0; i < n; i++)
			tests[i]();
	}
	else if (choice >= 0 && choice < n)
		tests[choice]();
	else
		std::cout << RED << "Test not valid" << RESET << std::endl;

	return 0;
}