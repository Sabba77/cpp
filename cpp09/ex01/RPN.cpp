#include "RPN.hpp"
#include <iostream>
#include <cctype>

RPN::RPN()
{
	std::cout << BLACK_GRAY << "DEFAULT CONSTRUCTOR CALLED" << RESET << std::endl;
}

RPN::RPN(const RPN& other) : stack(other.stack)
{
	std::cout << BLACK_GRAY << "COPY CONSTRUCTOR CALLED" << RESET << std::endl;
}

RPN& RPN::operator=(const RPN& other)
{
	std::cout << BLACK_GRAY << "COPY ASSIGNMENT OPERATOR CALLED" << RESET << std::endl;
	if (this != &other)
		this->stack = other.stack;
	return *this;
}

RPN::~RPN()
{
	std::cout << BLACK_GRAY << "DESTRUCTOR CALLED" << RESET << std::endl;
}

static bool isValidChar(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

void	RPN::calcRes(long n1, long n2, char sign)
{
	switch (sign)
	{
	case '+':
		stack.push(n1 + n2);
		break;
	case '-':
		stack.push(n1 - n2);
		break;
	case '*':
		stack.push(n1 * n2);
		break;
	case '/':
		if (n2 != 0)
			stack.push(n1 / n2);
		else
			throw ErrorException("Error: impossible to divide by zero!");
		break;
	default:
		break;
	}
}

RPN::RPN(const std::string& in)
{
	std::cout << BLACK_GRAY << "PARAMETRIC CONSTRUCTOR CALLED" << RESET << std::endl;

	if (in.empty())
		throw	ErrorException("Error: input is empty!");
	if (in.size() < 5)
		throw	ErrorException("Error: input must have at least 3 char, separated by space!");

	for (size_t i = 0; i < in.size(); i++)
	{
		if (in[i] == ' ')
			continue;
		
		if (!isdigit(static_cast<unsigned char>(in[i])) && !isValidChar(in[i]))
			throw ErrorException("Error: foreign character!");

		if (isdigit(static_cast<unsigned char>(in[i])) && (in[i + 1] == ' ' || in[i + 1] == '\0'))
			stack.push(in[i] - '0');
		else if (in[i + 1] != ' ' && in[i + 1] != '\0')
			throw ErrorException("Error: bad format line!");
		else if (isValidChar(in[i]) && stack.size() >= 2)
		{
			long	num2 = stack.top();
			stack.pop();
			long	num1 = stack.top();
			stack.pop();
			calcRes(num1, num2, in[i]);
		}
		else
			throw ErrorException("Error: sign must be after 2 numbers!");
	}
	if (stack.size() == 1)
		std::cout << stack.top() << std::endl;
	else
		throw ErrorException("Error: wrong expression!");
}