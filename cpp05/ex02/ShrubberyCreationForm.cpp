#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyNoName", 145, 137), target("ShrubberyNoNameTarget")
{
	std::cout << BLACK_GRAY << "SHRUBBERY DEFAULT CONSTRUCTOR CALLED" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), target(other.target)
{
	std::cout << BLACK_GRAY << "SHRUBBERY COPY CONSTRUCTOR CALLED" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& otherTarget)
	: AForm(otherTarget + "Shrubbery", 145, 137), target(otherTarget)
{
	std::cout << BLACK_GRAY << "SHRUBBERY PARAMETRIC CONSTRUCTOR CALLED" << RESET << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << BLACK_GRAY << "SHRUBBERY COPY ASSIGNMENT OPERATOR CALLED" << RESET << std::endl;
	if (this == &other)
		return *this;
	AForm::operator=(other);
	target = other.target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << BLACK_GRAY << "SHRUBBERY DESTRUCTOR CALLED" << RESET << std::endl;
}

void	ShrubberyCreationForm::executeAction() const
{
	std::ofstream	out((target + "_shrubbery").c_str(), std::ios::out);

	if (!out)
		throw std::runtime_error("failed opening");

	out << "          *          " << std::endl;
	out << "         ***         " << std::endl;
	out << "        *****        " << std::endl;
	out << "       *******       " << std::endl;
	out << "      *********      " << std::endl;
	out << "     ***********     " << std::endl;
	out << "    *************    " << std::endl;
	out << "   ***************   " << std::endl;
	out << "  *****************  " << std::endl;
	out << " ******************* " << std::endl;
	out << "          ||         " << std::endl;
	out << "          ||         " << std::endl;
}