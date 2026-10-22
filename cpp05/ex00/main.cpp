#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << BOLD_CYAN << "========== TEST 0: constr, operator<< and destr ==========" << RESET << std::endl;
	{
		Bureaucrat a("peppe", 7);
		std::cout << a << std::endl;
	}
	std::cout << BOLD_CYAN << "========== TEST 1: grade too high/low ==========" << RESET << std::endl;
	{
		try
		{
			Bureaucrat	b("Marco", 151);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		try
		{
			Bureaucrat	c("Pina", 0);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		
	}
	std::cout << BOLD_CYAN << "========== TEST 2: grade++ / grade-- ==========" << RESET << std::endl;
	{
		Bureaucrat	d("high", 1);
		Bureaucrat	f("low", 150);
		try
		{
			d.incrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		std::cout << d << std::endl;
		try
		{
			f.decrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		std::cout << f << std::endl;
		try
		{
			Bureaucrat g("peppe", 7);

			std::cout << g << std::endl;
			g.incrementGrade();
			std::cout << g << std::endl;
			g.decrementGrade();
			g.decrementGrade();
			std::cout << g << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}
}