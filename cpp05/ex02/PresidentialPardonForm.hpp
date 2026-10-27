#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include <iostream>

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string	target;

protected:
	void	executeAction() const;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	~PresidentialPardonForm();

	PresidentialPardonForm(const std::string& otherTarget);

};

#endif