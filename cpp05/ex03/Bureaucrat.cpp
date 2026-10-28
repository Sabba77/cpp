#include "AForm.hpp"
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("noName") , grade(150)
{
	std::cout << BLACK_GRAY << "[BUREAUCRAT " << name << "] DEFAULT CONSTRUCTOR CALLED" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& otherName, const int otherGrade) : name(otherName) , grade(otherGrade)
{
	std::cout << BLACK_GRAY << "[BUREAUCRAT " << name << "] PARAMETRIC CONSTRUCTOR CALLED" << RESET << std::endl;
	
	gradeCheck(grade);
	std::cout << GREEN << "Grade was set at " << grade << "!" << RESET << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << BLACK_GRAY << "[BUREAUCRAT " << name << "] DESTRUCTOR CALLED" << RESET << std::endl;
}

const std::string&	Bureaucrat::getName() const
{
	return name;
}

int	Bureaucrat::getGrade() const
{
	return grade;
}

void	Bureaucrat::incrementGrade()
{
	gradeCheck(grade - 1);
	grade--;
}

void	Bureaucrat::decrementGrade()
{
	gradeCheck(grade + 1);
	grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too High!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too Low!");
}

void	Bureaucrat::gradeCheck(int _grade) const
{
	if (_grade > LOWEST_POSSIBLE_GRADE)
		throw GradeTooLowException();
	if (_grade < HIGHEST_POSSIBLE_GRADE)
		throw GradeTooHighException();
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return out;
}

void	Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << "." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << getName() << " couldn't sign " << form.getName() << " because " << e.what() << "." << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm& form) const
{
	try
	{
		form.execute(*this);
		std::cout << getName() << " executed " << form.getName() << "." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << getName() << " couldn't execute " << form.getName() << " because " << e.what() << "." << std::endl;
	}
}
