#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

#define RED			"\033[31m"
#define GREEN		"\033[32m"
#define BOLD_CYAN	"\033[1;36m"
#define BLACK_GRAY	"\033[90m"
#define RESET		"\033[0m"

#define LOWEST_POSSIBLE_GRADE 150
#define HIGHEST_POSSIBLE_GRADE 1

class	Form;

class	Bureaucrat
{
private:
	const std::string	name;
	int					grade;

	void	gradeCheck(int _grade) const;

public:
	Bureaucrat();
	Bureaucrat(const std::string& otherName, const int otherGrade);

	~Bureaucrat();

	const std::string&	getName(void) const;
	int				getGrade(void) const;

	void	incrementGrade(void);
	void	decrementGrade(void);

	class	GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class	GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	void	signForm(Form& form);
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif