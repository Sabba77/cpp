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

AForm*	Intern::makeShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::makeRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidential(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& form, const std::string& target)
{
	AForm* (Intern::*functionForm[3])(const std::string&) =
	{ &Intern::makeShrubbery, &Intern::makeRobotomy, &Intern::makePresidential };

	std::string	possibleForm[9] =
	{ "ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm",
		"ShrubberyCreation", "RobotomyRequest", "PresidentialPardon",
		"shrubbery creation", "robotomy request", "presidential pardon" };
	
	for (int i = 0; i < 9; i++)
	{
		if (form == possibleForm[i])
		{
			std::cout << GREEN << "Intern creates " << form << RESET << std::endl;
			return (this->*functionForm[i % 3])(target);
		}
	}
	throw std::runtime_error("Unable to create, form does't exist!");
	return NULL;
}
