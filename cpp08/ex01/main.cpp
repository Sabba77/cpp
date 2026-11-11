#include "Span.hpp"

int main(void)
{
	std::cout << BOLD_CYAN << "========== MAIN TEST ==========" << RESET << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		
		std::cout << BOLD_CYAN << "--- out of range, span remains intact ---" << RESET << std::endl;
		try
		{
			sp.addNumber(20);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		std::cout << BOLD_CYAN << "--- add and span after sort ---" << RESET << std::endl;
		std::cout << BOLD_CYAN << "before:" << RESET << std::endl;
		Span	s = Span(5);
		s.addNumber(6);
		s.addNumber(3);
		s.addNumber(17);
		s.addNumber(9);
		std::cout << s.shortestSpan() << std::endl;
		std::cout << s.longestSpan() << std::endl;
		s.addNumber(11);
		std::cout << BOLD_CYAN << "after:" << RESET << std::endl;
		std::cout << s.shortestSpan() << std::endl;
		std::cout << s.longestSpan() << std::endl;
	}
	std::cout << BOLD_CYAN << "========== NEGATIVE AND EGUAL NUMBERS ==========" << RESET << std::endl;
	{
		Span negative = Span(4);
		negative.addNumber(-10);
		negative.addNumber(5);
		negative.addNumber(5);
		negative.addNumber(20);
		std::cout << "must be 0 : negative.shortestSpan() = " << negative.shortestSpan() << std::endl;
		std::cout << "must be 30 : negative.longestSpan() = "  << negative.longestSpan() << std::endl;
	}
	std::cout << BOLD_CYAN << "========== OCF TEST ==========" << RESET << std::endl;
	{
		Span sp1 = Span(5);
		sp1.addNumber(6);
		sp1.addNumber(3);
		sp1.addNumber(17);
		sp1.addNumber(9);
		sp1.addNumber(11);
		Span sp2(sp1);
		Span sp3 = Span(3);
		sp3.addNumber(1);
		sp3.addNumber(7);
		sp3.addNumber(15);
		sp3 = sp2;

		std::cout << "sp1.shortestSpan() = " << sp1.shortestSpan() << std::endl;
		std::cout << "sp1.longestSpan() = "  << sp1.longestSpan() << std::endl;
		std::cout << "sp2.shortestSpan() = " << sp2.shortestSpan() << std::endl;
		std::cout << "sp2.longestSpan() = "  << sp2.longestSpan() << std::endl;
		std::cout << "sp3.shortestSpan() = " << sp3.shortestSpan() << std::endl;
		std::cout << "sp3.longestSpan() = "  << sp3.longestSpan() << std::endl;
	}
	std::cout << BOLD_CYAN << "========== EXCEPTION TEST ==========" << RESET << std::endl;
	{
		std::cout << BOLD_CYAN << "--- exception error: no space available ---" << RESET << std::endl;
		try
		{
			Span sp = Span(5);
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			sp.addNumber(14);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		std::cout << BOLD_CYAN << "--- exception error: no span can be found (n = 0) ---" << RESET << std::endl;
		try
		{
			Span sp = Span(2);
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		std::cout << BOLD_CYAN << "--- exception error: no span can be found (n = 1) ---" << RESET << std::endl;
		try
		{
			Span sp = Span(2);
			sp.addNumber(6);
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		std::cout << BOLD_CYAN << "--- exception error: no space (template addNumber) ---" << RESET << std::endl;
		{
			try
			{
				Span	s = Span(3);
				std::vector<int> v;
				v.push_back(1);
				v.push_back(2);
				v.push_back(3);
				v.push_back(4);
				v.push_back(5);
				s.addNumber(v.begin(), v.end());
			}
			catch(const std::exception& e)
			{
				std::cout << e.what() << '\n';
			}
		}
	}
	std::cout << BOLD_CYAN << "========== 10000+ TEST ==========" << RESET << std::endl;
	{
		std::srand(std::time(NULL));
		
		unsigned int	n = 10000;
		std::vector<int>	vec(n);
		std::generate_n(vec.begin(), n, std::rand);
		Span	s = Span(n);
		s.addNumber(vec.begin(), vec.end());
		std::cout << s.shortestSpan() << std::endl;
		std::cout << s.longestSpan() << std::endl;
	}
	std::cout << BOLD_CYAN << "========== TEMPLATE TEST ==========" << RESET << std::endl;
	{
		std::cout << BOLD_CYAN << "--- vector test ---" << RESET << std::endl;
		{
			Span	s1 = Span(6);
			std::vector<int>	v;

			v.push_back(6);
			v.push_back(3);
			v.push_back(17);
			v.push_back(9);
			v.push_back(11);
			s1.addNumber(v.begin(), v.end());
			std::cout << s1.shortestSpan() << std::endl;
			std::cout << s1.longestSpan() << std::endl;
		}
		std::cout << BOLD_CYAN << "--- list test ---" << RESET << std::endl;
		{
			Span	s2 = Span(6);
			std::list<int>	l;

			l.push_back(6);
			l.push_back(3);
			l.push_back(17);
			l.push_back(9);
			l.push_back(11);
			s2.addNumber(l.begin(), l.end());
			std::cout << s2.shortestSpan() << std::endl;
			std::cout << s2.longestSpan() << std::endl;
		}
		std::cout << BOLD_CYAN << "--- deque test ---" << RESET << std::endl;
		{
			Span	s3 = Span(6);
			std::deque<int>	d;

			d.push_back(6);
			d.push_back(3);
			d.push_back(17);
			d.push_back(9);
			d.push_back(11);
			s3.addNumber(d.begin(), d.end());
			std::cout << s3.shortestSpan() << std::endl;
			std::cout << s3.longestSpan() << std::endl;
		}
		std::cout << BOLD_CYAN << "===== RANGE TOO BIG, SPAN REMAINS INTACT =====" << RESET << std::endl;
		{
			Span	sp = Span(5);
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			std::cout << "before: shortest = " << sp.shortestSpan()
					<< ", longest = " << sp.longestSpan() << std::endl;

			std::vector<int>	v;
			v.push_back(1);
			v.push_back(2);
			v.push_back(4);
			try
			{
				sp.addNumber(v.begin(), v.end());
			}
			catch (const std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
			std::cout << "after: shortest = " << sp.shortestSpan()
					<< ", longest = " << sp.longestSpan() << std::endl;

			sp.addNumber(1);
			sp.addNumber(2);
			std::cout << "two slots still free: shortest = " << sp.shortestSpan()
					<< ", longest = " << sp.longestSpan() << std::endl;
		}
	}
	return 0;
}