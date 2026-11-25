#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <sstream>
#include <exception>
#include <utility>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cerrno>
#include <ctime>
#include <iomanip>

# define RED			"\033[31m"
# define STRIKE_RED		"\033[9;31m"
# define GREEN			"\033[32m"
# define YELLOW			"\x1b[33m"
# define BOLD_CYAN		"\033[1;36m"
# define BLACK_GRAY		"\033[90m"
# define BLK_MAGENTA	"\x1b[95m"
# define RESET			"\033[0m"

class	PmergeMe
{
private:
	std::vector<int>	v;
	std::list<int>		l;
	double			vTime;
	double			lTime;
	size_t			count;
	std::string		before;

public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	PmergeMe(int ac, char** av);

	void	printBefore() const;
	void	printAfter() const;
	void	printVectorTime() const;
	void	printListTime() const;

	class ErrorException : public std::exception
	{
	private:
		std::string	message;
	public:
		explicit ErrorException(const std::string& msg) : message(msg)
		{
		}
		virtual const char* what() const throw()
		{
			return message.c_str();
		}
		virtual ~ErrorException() throw()
		{
		}
	};

private:
	void	sortVector(std::vector<int>& vec);
	void	sortList(std::list<int>& lis);

	// n-th Jacobsthal number (0, 1, 1, 3, 5, 11, 21, ...), closed form: (2^n - (-1)^n) / 3
	static size_t	jacobsthal(size_t n);

	void	parser(int ac, char** av);
	static double	timing();
};

#endif