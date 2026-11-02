#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << BLACK_GRAY << "INTERN DEFAULT CONSTRUCTOR CALLED" << RESET << std::endl;
}

Intern::Intern(const Intern&)
{
	std::cout << BLACK_GRAY << "INTERN COPY CONSTRUCTOR CALLED" << RESET << std::endl;
}

Intern& Intern::operator=(const Intern&)
{
	std::cout << BLACK_GRAY << "INTERN COPY ASSIGNMENT OPERATOR CALLED" << RESET << std::endl;
	return *this;
}

Intern::~Intern()
{
	std::cout << BLACK_GRAY << "INTERN DESTRUCTOR CALLED" << RESET << std::endl;
}

static AForm*	makeShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

static AForm*	makeRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

static AForm*	makePresidential(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& form, const std::string& target)
{
	static const FormEntry	table[] =
	{
		{ "ShrubberyCreationForm",	makeShrubbery },
		{ "ShrubberyCreation",		makeShrubbery },
		{ "shrubbery creation",		makeShrubbery },
		{ "RobotomyRequestForm",	makeRobotomy },
		{ "RobotomyRequest",		makeRobotomy },
		{ "robotomy request",		makeRobotomy },
		{ "PresidentialPardonForm",	makePresidential },
		{ "PresidentialPardon",		makePresidential },
		{ "presidential pardon",	makePresidential }
	};

	const size_t	size = sizeof(table) / sizeof(table[0]);

	for (size_t i = 0; i < size; i++)
	{
		if (form == table[i].name)
		{
			std::cout << GREEN << "Intern creates " << form << RESET << std::endl;
			return table[i].create(target);
		}
	}
	std::cout << RED << "Intern error: form \"" << form << "\" doesn't exist!" << RESET << std::endl;
	return NULL;
}