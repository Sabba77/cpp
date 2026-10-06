#include "Harl.hpp"

# include <iostream>

Harl::Harl()
{}

Harl::~Harl()
{}

void Harl::debug(void)
{
	std::cout << GREEN
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
		<< RESET << std::endl;
}

void Harl::info(void)
{
	std::cout << GREEN
		<< "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
		<< RESET << std::endl;
}

void Harl::warning(void)
{
	std::cout << GREEN
		<< "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month."
		<< RESET << std::endl;
}

void Harl::error(void)
{
	std::cout << GREEN
		<< "This is unacceptable! I want to speak to the manager now."
		<< RESET << std::endl;
}

void Harl::complain(std::string level)
{
	typedef void (Harl::*t_action)(void);

	static const char* names[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	static const t_action actions[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; ++i)
	{
		if (level == names[i])
		{
			(this->*actions[i])();
			return;
		}
	}
	std::cout << RED << "[ Probably complaining about insignificant problems ]" << RESET << std::endl;
}
