#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <ctime>


int	main(void)
{
	srand(time(NULL)); // for rand()

	std::cout << BOLD_CYAN << "========== TEST 0: default constructor with noName and new ==========" << RESET << std::endl;
	{
		try
		{
			AForm* a = new ShrubberyCreationForm();
			AForm* b = new RobotomyRequestForm();
			AForm* c = new PresidentialPardonForm();
			Bureaucrat pep("peppe", 5);

			pep.executeForm(*a);
			pep.executeForm(*b);
			pep.executeForm(*c);

			delete a;
			delete b;
			delete c;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}

	}
	std::cout << BOLD_CYAN << "========== TEST 1: ShrubberyCreation ==========" << RESET << std::endl;
	{
		std::cout << BOLD_CYAN << "Grade OK:" << RESET << std::endl;
		try
		{
			ShrubberyCreationForm	a("PeppeForm");
			Bureaucrat				b("Peppe", 135);
			std::cout << a << std::endl;
			std::cout << b << std::endl;
			b.signForm(a);
			b.executeForm(a);
			std::cout << a << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}

		std::cout << BOLD_CYAN << "\nOK sign, NO execute:" << RESET << std::endl;
		try
		{
			ShrubberyCreationForm	a("PeppeForm");
			Bureaucrat				b("Peppe", 140);
			std::cout << a << std::endl;
			std::cout << b << std::endl;
			b.signForm(a);
			b.executeForm(a);
			std::cout << a << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}

		std::cout << BOLD_CYAN << "\nNO sign, NO execute:" << RESET << std::endl;
		try
		{
			ShrubberyCreationForm	a("PeppeForm");
			Bureaucrat				b("Peppe", 146);
			std::cout << a << std::endl;
			std::cout << b << std::endl;
			b.signForm(a);
			b.executeForm(a);
			std::cout << a << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}

		std::cout << BOLD_CYAN << "\nExecute with no sign:" << RESET << std::endl;
		try
		{
			ShrubberyCreationForm	a("PeppeForm");
			Bureaucrat				b("Peppe", 130);
			std::cout << a << std::endl;
			std::cout << b << std::endl;
			a.execute(b);
			std::cout << a << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}
	std::cout << BOLD_CYAN << "========== TEST 2: RobotomyRequest ==========" << RESET << std::endl;
	{
		std::cout << BOLD_CYAN << "\nGrade OK, execute in loop, check rand():" << RESET << std::endl;
		try
		{
			RobotomyRequestForm	a("PinoForm");
			Bureaucrat			b("Pino", 45);
			std::cout << a << std::endl;
			std::cout << b << std::endl;
			b.signForm(a);
			for (int i = 0; i < 10; i++)
				b.executeForm(a);
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}

		std::cout << BOLD_CYAN << "\nOK sign, NO execute:" << RESET << std::endl;
		try
		{
			RobotomyRequestForm	a("PinoForm");
			Bureaucrat			b("Pino", 72);
			std::cout << a << std::endl;
			std::cout << b << std::endl;
			b.signForm(a);
			b.executeForm(a);
			std::cout << a << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}

		std::cout << BOLD_CYAN << "\nNO sign, NO execute:" << RESET << std::endl;
		try
		{
			RobotomyRequestForm	a("PinoForm");
			Bureaucrat			b("Pino", 73);
			std::cout << a << std::endl;
			std::cout << b << std::endl;
			b.signForm(a);
			b.executeForm(a);
			std::cout << a << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}
	std::cout << BOLD_CYAN << "========== TEST 3: PresidentialPardon ==========" << RESET << std::endl;
	{
		std::cout << BOLD_CYAN << "\nGrade OK:" << RESET << std::endl;
		try
		{
			PresidentialPardonForm	a("NinoForm");
			Bureaucrat				b("Nino", 5);
			std::cout << a << std::endl;
			std::cout << b << std::endl;
			b.signForm(a);
			b.executeForm(a);
			std::cout << a << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}

		std::cout << BOLD_CYAN << "\nOK sign, NO execute:" << RESET << std::endl;
		try
		{
			PresidentialPardonForm	a("NinoForm");
			Bureaucrat				b("Nino", 25);
			std::cout << a << std::endl;
			std::cout << b << std::endl;
			b.signForm(a);
			b.executeForm(a);
			std::cout << a << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}

		std::cout << BOLD_CYAN << "\nNO sign, NO execute:" << RESET << std::endl;
		try
		{
			PresidentialPardonForm	a("NinoForm");
			Bureaucrat				b("Nino", 26);
			std::cout << a << std::endl;
			std::cout << b << std::endl;
			b.signForm(a);
			b.executeForm(a);
			std::cout << a << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}

	std::cout << BOLD_CYAN << "========== TEST 4: execute() ==========" << RESET << std::endl;
	{
		std::cout << BOLD_CYAN << "\nerror: grade too low" << RESET << std::endl;
		try
		{
			PresidentialPardonForm	a("NanoForm");
			Bureaucrat				b("Nano", 25);
			a.execute(b);

		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}

		std::cout << BOLD_CYAN << "\nerror: not signed" << RESET << std::endl;
		try
		{
			PresidentialPardonForm	a("NanoForm");
			Bureaucrat				b("Nano", 5);
			a.execute(b);

		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}

	std::cout << BOLD_CYAN << "========== TEST 5: copy and assignamet check _signed ==========" << RESET << std::endl;
	{
		std::cout << BOLD_CYAN << "\nCopy constructor" << RESET << std::endl;
		try
		{
			PresidentialPardonForm	a("signForm");
			Bureaucrat				b("Sign", 5);

			std::cout << a << std::endl;
			a.beSigned(b);
			std::cout << a << std::endl;

			PresidentialPardonForm	c(a);
			std::cout << c << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}

		std::cout << BOLD_CYAN << "\nCopy assignment operator" << RESET << std::endl;
		try
		{
			PresidentialPardonForm	a("signForm");
			PresidentialPardonForm	c("noSignForm");
			Bureaucrat				b("Sign", 5);

			std::cout << a << std::endl;
			std::cout << c << std::endl;
			a.beSigned(b);
			std::cout << a << std::endl;

			c = a;
			std::cout << c << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}
	std::cout << BOLD_CYAN << "--- TEST: errore apertura file ---" << RESET << std::endl;
	{

		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm bad("cartella_inesistente/home");

		boss.signForm(bad);
		boss.executeForm(bad);
	}
}