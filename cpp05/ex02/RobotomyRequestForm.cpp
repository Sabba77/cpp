#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyNoName", 72, 45), target("RobotomyNoNameTarget")
{
	std::cout << BLACK_GRAY << "ROBOTOMY DEFAULT CONSTRUCTOR CALLED" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), target(other.target)
{
	std::cout << BLACK_GRAY << "ROBOTOMY COPY CONSTRUCTOR CALLED" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& otherTarget)
	: AForm(otherTarget + "Robotomy", 72, 45), target(otherTarget)
{
	std::cout << BLACK_GRAY << "ROBOTOMY PARAMETRIC CONSTRUCTOR CALLED" << RESET << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << BLACK_GRAY << "ROBOTOMY COPY ASSIGNMENT OPERATOR CALLED" << RESET << std::endl;
	if (this == &other)
		return *this;
	AForm::operator=(other);
	target = other.target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << BLACK_GRAY << "ROBOTOMY DESTRUCTOR CALLED" << RESET << std::endl;
}

void	RobotomyRequestForm::executeAction() const
{
	std::cout << GREEN << "Bzzzzzzzz............" << RESET << std::endl;

	if (std::rand() % 2 == 0)
		std::cout << GREEN << target << " has been robotomized successfully." << RESET << std::endl;
	else
		std::cout << RED << "Robotomy failed for " << target << "." << RESET << std::endl;
}
