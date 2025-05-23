#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, int toSign, int toExec) : name(name), isSigned(false), gradeToSign(toSign), gradeToExec(toExec)
{
	if (toSign > 150 || toExec > 150)
		throw (GradeTooLowExcept());
	else if (toSign <= 0 || toExec <= 0)
		throw (GradeTooHighExcept());
	std::cout << BRIGHT_GREEN << this->getName() << "(form): constructor called.\n" RESET;
}
AForm::AForm(const AForm &other) : name(other.getName()), isSigned(other.getIsSigned()), gradeToSign(other.getGradeToSign()), gradeToExec(other.getGradeToExec())
{
	std::cout << BRIGHT_GREEN << this->getName() << "(form): copy constructor called.\n" RESET;
}
AForm&	AForm::operator=(const AForm &other)
{
	std::cout << BRIGHT_GREEN << this->getName() << "(form): assignment operator.\n" RESET;
	if (this != &other)
		isSigned = other.getIsSigned();
	return (*this);
}
AForm::~AForm()
{
	std::cout << BRIGHT_RED << this->getName() << "(form): destructor called.\n" RESET;
}

static std::string	itos(int n)
{
	std::string	str;
	if (n == 0)
		return ("0");
	while (n > 0)
	{
		str.insert(str.begin(), '0' + (n % 10));
		n /= 10;
	}
	return (str);
}

std::ostream &operator<<(std::ostream &out, const AForm &other)
{
	out << other.getName() + "(form); Is signed: " + (other.getIsSigned() ? "yes": "no") + "; Grade to sign: " + itos(other.getGradeToSign()) + "; Grade to execute: " + itos(other.getGradeToExec());
	return (out);
}


std::string	AForm::getName(void) const
{
	return (name);
}
bool		AForm::getIsSigned(void) const
{
	return (isSigned);
}
int			AForm::getGradeToSign(void) const
{
	return (gradeToSign);
}
int			AForm::getGradeToExec(void) const
{
	return (gradeToExec);
}

// void	AForm::beSigned(const Bureaucrat &other)
// {
// 	if (other.getGrade() > gradeToSign)
// 	{
// 		std::cout << ORANGE << other.getName() << "(bureaucrat): Has no grade enough to sign " << this->getName() << "\n" RESET;
// 		return ;
// 	}
// 	this->isSigned = true;
// 	std::cout << ORANGE << other.getName() << "(bureaucrat): signed " << this->getName() << " \n" RESET;
// }
