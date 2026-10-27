#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

#define RED			"\033[31m"
#define GREEN		"\033[32m"
#define YELLOW		"\x1b[33m"
#define BOLD_CYAN	"\033[1;36m"
#define BLACK_GRAY	"\033[90m"
#define RESET		"\033[0m"

#define LOWEST_POSSIBLE_GRADE 150
#define HIGHEST_POSSIBLE_GRADE 1

class	Bureaucrat;

class AForm
{
private:
	const std::string	name;
	bool		_signed;
	const int	gradeToSign;
	const int	gradeToExecute;

protected:
	virtual void executeAction() const = 0;
	void	gradeCheck(int grade) const;

public:
	AForm();
	AForm(const AForm& otherAForm);
	AForm& operator=(const AForm& otherAForm);

	virtual ~AForm();

	AForm(const std::string& oName, const int oGradeToSign, const int oGradeToExecute);

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
	
	class	FormNotSignedException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	void	beSigned(const Bureaucrat& Bureau);
	void	execute(Bureaucrat const & executor) const;
};

std::ostream&	operator<<(std::ostream& out, const AForm& AForm);

#endif