#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include <iostream>
#include <cstdlib>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string	target;

protected:
	void	executeAction() const;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	~RobotomyRequestForm();

	RobotomyRequestForm(const std::string& otherTarget);

};

#endif