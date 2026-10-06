#ifndef HARL_HPP
# define HARL_HPP

# include <string>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define	BLUE	"\033[1;36m"
#define BOLD_BLINK	"\033[1;5;31m"
#define RESET   "\033[0m"

class Harl
{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
	public:
		Harl();
		~Harl();

		void complain(std::string level);
};

#endif
