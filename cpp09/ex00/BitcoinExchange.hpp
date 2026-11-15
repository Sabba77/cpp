#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
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


class	BitcoinExchange
{
private:
	std::map<std::string, double>	db;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	explicit BitcoinExchange(const std::string& filename);
	void	processFile(const std::string& filename) const;
private:
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
	
	bool	isValidDate(const std::string& dateLine) const;
	bool	isValidValue(const std::string& valueLine, double& value) const;
};

#endif