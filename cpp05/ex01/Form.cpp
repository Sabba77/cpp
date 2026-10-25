#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : name("noName"), _signed(false), gradeToSign(150), gradeToExecute(150)
{
	std::cout << BLACK_GRAY << "[FORM " << name << "] DEFAULT CONSTRUCTOR CALLED" << RESET << std::endl;
}

Form::Form(const Form& otherForm) : name(otherForm.name), _signed(otherForm._signed),
	gradeToSign(otherForm.gradeToSign), gradeToExecute(otherForm.gradeToExecute)
{
	std::cout << BLACK_GRAY << "[FORM " << name << "] COPY CONSTRUCTOR CALLED" << RESET << std::endl;
}

Form::Form(const std::string& oName, const int oGradeToSign, const int oGradeToExecute) :
	name(oName), _signed(false), gradeToSign(oGradeToSign), gradeToExecute(oGradeToExecute)
{
	std::cout << BLACK_GRAY << "[FORM " << name << "] PARAMETRIC CONSTRUCTOR CALLED" << RESET << std::endl;

	gradeCheck(gradeToSign);
	gradeCheck(gradeToExecute);
}

Form::~Form()
{
	std::cout << BLACK_GRAY << "[FORM " << name << "] DESTRUCTOR CALLED" << RESET << std::endl;
}

Form& Form::operator=(const Form& otherForm)
{
	std::cout << BLACK_GRAY << "[FORM " << name << "] ASSIGNMENT OPERATOR CALLED" << RESET << std::endl;

	if (this == &otherForm)
		return *this;
	_signed = otherForm._signed;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Form& Form)
{
	out << Form.getName() << ", form signed " << Form.getSigned() << ". Grade to sign: "
		<< Form.getGradeToSign() << ". Grade to execute: " << Form.getGradeToExecute() << ".";
	return out;
}

const std::string& Form::getName(void) const
{
	return name;
}

bool	Form::getSigned(void) const
{
	return _signed;
}

int	Form::getGradeToSign(void) const
{
	return gradeToSign;
}

int	Form::getGradeToExecute(void) const
{
	return gradeToExecute;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form grade is too low!";
}

void	Form::beSigned(const Bureaucrat& Bureau)
{
	if (Bureau.getGrade() > gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

void	Form::gradeCheck(int grade) const
{
	if (grade > LOWEST_POSSIBLE_GRADE)
		throw GradeTooLowException();
	if (grade < HIGHEST_POSSIBLE_GRADE)
		throw GradeTooHighException();
}
