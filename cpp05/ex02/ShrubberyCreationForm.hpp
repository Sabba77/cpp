#ifndef SHRUBBERRYCREATIONFORM_HPP
# define SHRUBBERRYCREATIONFORM_HPP

#include <string>
#include <iostream>

#include <stdexcept>
#include <fstream>

#include "AForm.hpp"

class	ShrubberyCreationForm : public AForm
{
private:
	std::string	target;

protected:
	void	executeAction() const;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

	ShrubberyCreationForm(const std::string& target);
};

#endif