#include "easyfind.hpp"

#define RESET	"\033[0m"
#define CYAN	"\033[1;36m"
#define GREEN	"\033[32m"
#define RED		"\033[31m"

static void	title(const std::string& name)
{
	std::cout << CYAN << "[TEST] " << name << RESET << std::endl;
}

int	main(void)
{
	// ---------- vector ----------
	std::vector<int> vec;
	vec.push_back(7);
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(23);
	vec.push_back(15);

	title("vector: value in the middle");
	try
	{
		std::vector<int>::iterator it = easyfind(&vec, 3);
		std::cout << GREEN << "Found: " << *it
				  << " at position " << std::distance(vec.begin(), it)
				  << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	title("vector: first element");
	try
	{
		std::vector<int>::iterator it = easyfind(&vec, 7);
		std::cout << GREEN << "Found: " << *it
				  << " at position " << std::distance(vec.begin(), it)
				  << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	title("vector: last element");
	try
	{
		std::vector<int>::iterator it = easyfind(&vec, 15);
		std::cout << GREEN << "Found: " << *it
				  << " at position " << std::distance(vec.begin(), it)
				  << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	title("vector: value missing");
	try
	{
		std::vector<int>::iterator it = easyfind(&vec, 26);
		std::cout << GREEN << "Found: " << *it << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	std::vector<int> dup;
	dup.push_back(7);
	dup.push_back(3);
	dup.push_back(3);

	title("vector: duplicated value (must return the FIRST occurrence)");
	try
	{
		std::vector<int>::iterator it = easyfind(&dup, 3);
		std::cout << GREEN << "Found: " << *it
				  << " at position " << std::distance(dup.begin(), it)
				  << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	std::vector<int> empty;

	title("vector: empty container");
	try
	{
		std::vector<int>::iterator it = easyfind(&empty, 3);
		std::cout << GREEN << "Found: " << *it << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	// ---------- list ----------
	std::list<int> lst;
	lst.push_back(7);
	lst.push_back(1);
	lst.push_back(3);
	lst.push_back(23);
	lst.push_back(15);

	title("list: value present");
	try
	{
		std::list<int>::iterator it = easyfind(&lst, 23);
		std::cout << GREEN << "Found: " << *it
				  << " at position " << std::distance(lst.begin(), it)
				  << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	title("list: value missing");
	try
	{
		std::list<int>::iterator it = easyfind(&lst, 26);
		std::cout << GREEN << "Found: " << *it << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	// ---------- deque ----------
	std::deque<int> deq;
	deq.push_back(7);
	deq.push_back(1);
	deq.push_back(3);
	deq.push_back(23);
	deq.push_back(15);

	title("deque: value present");
	try
	{
		std::deque<int>::iterator it = easyfind(&deq, 1);
		std::cout << GREEN << "Found: " << *it
				  << " at position " << std::distance(deq.begin(), it)
				  << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	title("deque: value missing");
	try
	{
		std::deque<int>::iterator it = easyfind(&deq, 26);
		std::cout << GREEN << "Found: " << *it << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	return (0);
}