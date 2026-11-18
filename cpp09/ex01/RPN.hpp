#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>
#include <exception>

#define RED			"\033[31m"
#define STRIKE_RED	"\033[9;31m"
#define GREEN		"\033[32m"
#define YELLOW		"\x1b[33m"
#define BOLD_CYAN	"\033[1;36m"
#define BLACK_GRAY	"\033[90m"
#define BLK_MAGENTA	"\x1b[95m"
#define RESET		"\033[0m"


class	RPN
{
private:
	std::stack<long>	stack;
	void	calcRes(long n1, long n2, char sign);

public:
	RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();

	RPN(const std::string& in);

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
};

#endif