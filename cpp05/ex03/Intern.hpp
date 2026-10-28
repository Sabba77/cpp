#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class AForm;

class	Intern
{
public:
	Intern();
	Intern(const Intern&);
	Intern& operator=(const Intern&);
	~Intern();
	
	AForm*	makeForm(const std::string& form, const std::string& target);
	AForm*	makeShrubbery(const std::string& target);
	AForm*	makeRobotomy(const std::string& target);
	AForm*	makePresidential(const std::string& target);

};

#endif