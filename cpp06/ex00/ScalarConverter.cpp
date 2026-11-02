#include "ScalarConverter.hpp"
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <iomanip>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter&)
{
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&)
{
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

enum strType
{
	INVALID,
	PSEUDO,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

static bool	isPseudo(const std::string& str)
{
	return ( str == "+inf" || str == "-inf" || str == "nan" ||
			str == "+inff" || str == "-inff" || str == "nanf" );
}

static bool	isChar(const std::string& str)
{
	if (str.length() == 1)
		return !std::isdigit(static_cast<unsigned char>(str[0]));
	else if (str.length() == 3)
		return (str[0] == '\'' && str[2] == '\'');
	else
		return false;
}
static bool	isInt(const std::string& str)
{
	size_t	i = 0;

	if (str.empty())
		return false;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (i >= str.length())
		return false;
	while (i < str.length())
	{
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return false;
		i++;
	}
	return true;
}

static bool	isDecimal(const std::string& str)
{
	size_t i = 0, point = 0, num = 0;

	if (str.empty())
		return false;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (i >= str.length())
		return false;
	while (i < str.length())
	{
		if (str[i] == '.')
			point++;
		else if (std::isdigit(static_cast<unsigned char>(str[i])))
			num++;
		else
			return false;
		i++;
	}
	if (point == 1 && num >= 1)
		return true;
	return false;
}

static bool	isFloat(const std::string& str)
{
	return (str.length() >= 3 && str[str.length() - 1] == 'f' && isDecimal(str.substr(0, str.length() - 1)));
}

static bool	isDouble(const std::string& str)
{
	return isDecimal(str);
}

static void	printPseudo(const std::string& str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: "
		<< ((str.rfind("inff") != std::string::npos || str.rfind("nanf") != std::string::npos) ? str : str + "f")
		<< std::endl;
	std::cout << "double: "
		<< ((str.rfind("inff") != std::string::npos || str.rfind("nanf") != std::string::npos) ? str.substr(0, str.size() - 1) : str)
		<< std::endl;
}

static void	printChar(const double d)
{
	if (d < CHAR_MIN || d > CHAR_MAX)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<unsigned char>(static_cast<char>(d))))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
}

static void	printInt(const double d)
{
	if (d >= INT_MIN && d <= INT_MAX)
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
}

static void	printFloat(const double d)
{
	if (d >= -FLT_MAX && d <= FLT_MAX)
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
	else
		std::cout << "float: impossible" << std::endl;
}

static void	printDouble(const double d)
{
	if (d >= -DBL_MAX && d <= DBL_MAX)
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	else
		std::cout << "double: impossible" << std::endl;
}

static void	printValue(const double d)
{
	printChar(d);
	printInt(d);
	printFloat(d);
	printDouble(d);
}

static double	getValue(const std::string& str, strType type)
{
	if (type == CHAR)
		return (str[0] == '\'' ? static_cast<double>(str[1]) : static_cast<double>(str[0]));
	else
		return (std::strtod(str.c_str(), NULL));
}

static strType checkType(const std::string& str)
{
	if (isPseudo(str))
		return PSEUDO;
	else if (isChar(str))
		return CHAR;
	else if (isInt(str))
		return INT;
	else if (isFloat(str))
		return FLOAT;
	else if (isDouble(str))
		return DOUBLE;
	else
		return INVALID;
}

void	ScalarConverter::convert(const std::string& str)
{
	strType	type = checkType(str);
	/* std::string testArray[] = {
		"INVALID", "PSEUDO", "CHAR", "INT", "FLOAT", "DOUBLE" };
	std::cout << testArray[type] << std::endl; */
	switch (type)
	{
	case INVALID:
		std::cout << "INVALID TYPE" << std::endl;
		break;
	case PSEUDO:
		printPseudo(str);
		break;
	case CHAR:
		printValue(getValue(str, type));
		break;
	case INT:
		printValue(getValue(str, type));
		break;
	case FLOAT:
		printValue(getValue(str, type));
		break;
	case DOUBLE:
		printValue(getValue(str, type));
		break;
	default:
		break;
	}
}