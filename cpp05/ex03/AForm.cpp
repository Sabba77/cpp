#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : name("noName"), _signed(false), gradeToSign(150), gradeToExecute(150)
{
	std::cout << BLACK_GRAY << "[AForm " << name << "] DEFAULT CONSTRUCTOR CALLED" << RESET << std::endl;
}

AForm::AForm(const AForm& otherAForm) : name(otherAForm.name), _signed(otherAForm._signed),
	gradeToSign(otherAForm.gradeToSign), gradeToExecute(otherAForm.gradeToExecute)
{
	std::cout << BLACK_GRAY << "[AForm " << name << "] COPY CONSTRUCTOR CALLED" << RESET << std::endl;
}
AForm::AForm(const std::string& oName, const int oGradeToSign, const int oGradeToExecute) :
	name(oName), _signed(false), gradeToSign(oGradeToSign), gradeToExecute(oGradeToExecute)
{
	std::cout << BLACK_GRAY << "[AForm " << name << "] PARAMETRIC CONSTRUCTOR CALLED" << RESET << std::endl;

	gradeCheck(gradeToSign);
	gradeCheck(gradeToExecute);
}

AForm::~AForm()
{
	std::cout << BLACK_GRAY << "[AForm " << name << "] DESTRUCTOR CALLED" << RESET << std::endl;
}

AForm& AForm::operator=(const AForm& otherAForm)
{
	std::cout << BLACK_GRAY << "[AForm " << name << "] ASSIGNMENT OPERATOR CALLED" << RESET << std::endl;

	if (this == &otherAForm)
		return *this;
	_signed = otherAForm._signed;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const AForm& aform)
{
	out << aform.getName() << ", AForm signed " << std::boolalpha << aform.getSigned() << std::noboolalpha << ". Grade to sign: "
		<< aform.getGradeToSign() << ". Grade to execute: " << aform.getGradeToExecute() << ".";
	return out;
}

const std::string& AForm::getName(void) const
{
	return name;
}

bool	AForm::getSigned(void) const
{
	return _signed;
}

int	AForm::getGradeToSign(void) const
{
	return gradeToSign;
}

int	AForm::getGradeToExecute(void) const
{
	return gradeToExecute;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "AForm grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

void	AForm::beSigned(const Bureaucrat& Bureau)
{
	if (Bureau.getGrade() > gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

void	AForm::gradeCheck(int grade) const
{
	if (grade > LOWEST_POSSIBLE_GRADE)
		throw GradeTooLowException();
	if (grade < HIGHEST_POSSIBLE_GRADE)
		throw GradeTooHighException();
}

void	AForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > gradeToExecute)
		throw GradeTooLowException();
	else if (getSigned() != true)
		throw FormNotSignedException();

	executeAction();
}
