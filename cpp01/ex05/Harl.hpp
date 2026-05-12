#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl {
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

	public:
		Harl();
		~Harl();

		// Chiama una delle 4 funzioni private in base a "level".
		void complain(std::string level);
};

#endif
