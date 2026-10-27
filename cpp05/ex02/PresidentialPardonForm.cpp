#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialNoName", 25, 5), target("PresidentialNoNameTarget")
{
	std::cout << BLACK_GRAY << "PRESIDENTIAL DEFAULT CONSTRUCTOR CALLED" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), target(other.target)
{
	std::cout << BLACK_GRAY << "PRESIDENTIAL COPY CONSTRUCTOR CALLED" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& otherTarget)
	: AForm(otherTarget + "Presidential", 25, 5), target(otherTarget)
{
	std::cout << BLACK_GRAY << "PRESIDENTIAL PARAMETRIC CONSTRUCTOR CALLED" << RESET << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	std::cout << BLACK_GRAY << "PRESIDENTIAL COPY ASSIGNMENT OPERATOR CALLED" << RESET << std::endl;
	if (this == &other)
		return *this;
	AForm::operator=(other);
	target = other.target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << BLACK_GRAY << "PRESIDENTIAL DESTRUCTOR CALLED" << RESET << std::endl;
}

void	PresidentialPardonForm::executeAction() const
{
	std::cout << GREEN << target << " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
}
