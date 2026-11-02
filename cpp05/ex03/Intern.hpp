#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class AForm;

class	Intern
{
private:
	struct FormEntry
	{
		const char*	name;
		AForm*		(*create)(const std::string&);
	};

public:
	Intern();
	Intern(const Intern&);
	Intern& operator=(const Intern&);
	~Intern();
	
	AForm* makeForm(const std::string& form, const std::string& target);

};

#endif