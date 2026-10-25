#ifndef FORM_HPP
# define FORM_HPP

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

class	Bureaucrat;

class Form
{
private:
	const std::string	name;
	bool		_signed;
	const int	gradeToSign;
	const int	gradeToExecute;

	void	gradeCheck(int grade) const;

public:
	Form();
	~Form();
	Form(const Form& otherForm);
	Form& operator=(const Form& otherForm);

	Form(const std::string& oName, const int oGradeToSign, const int oGradeToExecute);

	const std::string& getName(void) const;
	bool		getSigned(void) const;
	int			getGradeToSign(void) const;
	int			getGradeToExecute(void) const;


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

	void beSigned(const Bureaucrat& Bureau);
};

std::ostream&	operator<<(std::ostream& out, const Form& Form);

#endif