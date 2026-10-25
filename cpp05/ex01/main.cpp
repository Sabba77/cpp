#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << BOLD_CYAN << "========== TEST 0: constr, operator<< and destr ==========" << RESET << std::endl;
	{
		Form	a("peppe", 50, 10);
		Form	b(a);
		Form	c = b;

		std::cout << c << std::endl;
	}
	std::cout << BOLD_CYAN << "========== TEST 1: invalid grade ==========" << RESET << std::endl;
	{
		try
		{
			Form	a("peppe", -20, 10);

			std::cout << a << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}
	std::cout << BOLD_CYAN << "========== TEST 2: beSigned() ==========" << RESET << std::endl;
	{
		try
		{
			Form	a("Peppe Form", 10, 10);
			Bureaucrat b("Peppe", 7);

			std::cout << a << '\n' << b << std::endl;

			std::cout << std::boolalpha << a.getSigned() << std::endl;
			a.beSigned(b);			
			std::cout << a.getSigned() << std::noboolalpha << std::endl;

		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}
	std::cout << BOLD_CYAN << "========== TEST 3: signForm() ==========" << RESET << std::endl;
	{
		try
		{
			Bureaucrat	a("Pino", 11);
			Form		b("NoPinoForm", 10, 10);
			Form		c("YesPinoForm", 20, 10);

			std::cout << a << '\n' << b << std::endl;

			std::cout << BOLD_CYAN << "no sign pino form :" << RESET << std::endl;
			std::cout << std::boolalpha << b.getSigned() << std::endl;
			a.signForm(b);
			std::cout << std::boolalpha << b.getSigned() << std::noboolalpha << std::endl;

			std::cout << BOLD_CYAN << "yes sign pino form :" << RESET << std::endl;
			std::cout << std::boolalpha << c.getSigned() << std::endl;
			a.signForm(c);
			std::cout << std::boolalpha << c.getSigned() << std::noboolalpha << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}
	std::cout << BOLD_CYAN << "========== TEST 4: Form with invalide grade ==========" << RESET << std::endl;
	{
		try
		{
			Bureaucrat	a("Pino", 1);
			Form		b("NoPinoForm", 151, 150);

			std::cout << a << '\n' << b << std::endl;

			std::cout << std::boolalpha << b.getSigned() << std::endl;
			a.signForm(b);
			std::cout << std::boolalpha << b.getSigned() << std::noboolalpha << std::endl;

		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}
}