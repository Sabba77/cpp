#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstddef>
#include <cstdlib>
#include <cctype>
#include <iomanip>

BitcoinExchange::BitcoinExchange()
{
	std::cout << BLACK_GRAY << "DEFAULT CONSTRUCTOR CALLED" << RESET << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	std::cout << BLACK_GRAY << "COPY CONSTRUCTOR CALLED" << RESET << std::endl;
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	std::cout << BLACK_GRAY << "COPY ASSIGNMENT OPERATOR CALLED" << RESET << std::endl;
	if (this != &other)
		this->db = other.db;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << BLACK_GRAY << "DESTRUCTOR CALLED" << RESET << std::endl;
}

bool	BitcoinExchange::isValidDate(const std::string& dateLine) const
{
	if (dateLine.size() != 10)
		return false;
	if (dateLine[4] != '-' || dateLine[7] != '-')
		return false;

	if (!isdigit(static_cast<unsigned char>(dateLine[0])) || !isdigit(static_cast<unsigned char>(dateLine[1]))
		|| !isdigit(static_cast<unsigned char>(dateLine[2])) || !isdigit(static_cast<unsigned char>(dateLine[3]))
		|| !isdigit(static_cast<unsigned char>(dateLine[5])) || !isdigit(static_cast<unsigned char>(dateLine[6]))
		|| !isdigit(static_cast<unsigned char>(dateLine[8])) || !isdigit(static_cast<unsigned char>(dateLine[9])))
		return false;

	int		year = 0;
	int		month = 0;
	int		day = 0;
	char	sign1, sign2;
	std::istringstream	ss(dateLine);
	ss >> year >> sign1 >> month >> sign2 >> day;
	(void)sign1;
	(void)sign2;

	int	days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		days[1] = 29;

	if (month <= 0 || month > 12)
		return false;
	if (day <= 0 || day > days[month - 1])
		return false;
	return true;
}

bool	BitcoinExchange::isValidValue(const std::string& valueLine, double& value) const
{
	size_t	i = 0;
	size_t	dots = 0;
	size_t	digits = 0;

	if (!valueLine.empty() && valueLine[0] == '-')
		i++;
	for (; i < valueLine.size(); i++)
	{
		if (valueLine[i] == '.')
			dots++;
		else if (isdigit(static_cast<unsigned char>(valueLine[i])))
			digits++;
		else
			return false;
	}
	if (dots > 1 || digits == 0)
		return false;
	value = std::strtod(valueLine.c_str(), NULL);
	return true;
}

BitcoinExchange::BitcoinExchange(const std::string& filename)
{
	std::cout << BLACK_GRAY << "PARAMETRIC CONSTRUCTOR CALLED" << RESET << std::endl;

	std::ifstream	in(filename.c_str());
	if (!in.is_open())
		throw ErrorException("Error: unable to open file!");

	std::string	line;
	std::getline(in, line);
	if (line != "date,exchange_rate")
		throw ErrorException("Error: incorrect file header ");

	while (std::getline(in, line))
	{
		size_t	commaPos = line.find(',');
		if (commaPos == std::string::npos)
			throw ErrorException("Error: bad line format");

		std::string	dateLine = line.substr(0, commaPos);
		if (!isValidDate(dateLine))
			throw ErrorException("Error: invalid date in database!");
		std::string	valueLine = line.substr(commaPos + 1);

		double	rate;
		if (!isValidValue(valueLine, rate) || rate < 0)
			throw ErrorException("Error: invalid value in database!");
		if (!db.insert(std::make_pair(dateLine, rate)).second)
			throw ErrorException("Error: duplicate date!");
	}
}

void	BitcoinExchange::processFile(const std::string& filename) const
{
	std::ifstream	in(filename.c_str());
	if (!in.is_open())
		throw ErrorException("Error: could not open file.");

	std::string	line;
	std::getline(in, line);
	if (line != "date | value")
		throw ErrorException("Error: incorrect file header.");

	std::cout << std::setprecision(10); //
	while (std::getline(in, line))
	{
		size_t	sepPos = line.find(" | ");
		if (sepPos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string	dateLine = line.substr(0, sepPos);
		if (!isValidDate(dateLine))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string	valueLine = line.substr(sepPos + 3);
		double		value;
		if (!isValidValue(valueLine, value))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		else if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		else if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		std::map<std::string, double>::const_iterator	it = db.upper_bound(dateLine);
		if (it == db.begin())
		{
			std::cerr << RED << "Error: match not found!" << RESET << std::endl;
			continue;
		}
		--it;
		
		std::cout << dateLine << " => " << value << " = " << (value * it->second) << std::endl;
	}
}