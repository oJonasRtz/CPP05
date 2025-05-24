#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm(target, 25, 5), target(target)
{
	std::cout << BRIGHT_GREEN "President: constructor called\n" RESET;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other.getTarget(), 25, 5), target(other.getTarget())
{
	std::cout << BRIGHT_GREEN "President: copy constructor called\n" RESET;
}
PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << BRIGHT_GREEN "President: assignment operator\n" RESET;
	if (this != &other)
		this->target = other.getTarget();
	return (*this);
}
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << BRIGHT_RED "President: destructor called\n" RESET;
}

std::ostream	&operator<<(std::ostream &out, const PresidentialPardonForm &other)
{
	out << 
		"(President)target: " << other.getTarget() <<
		"; Grade to sign: " << other.getGradeToSign() <<
		"; Grade to execute: " << other.getGradeToExec() <<
		"; Is signed: " << (other.getIsSigned() ? "yes" : "no");
	return (out);
}

std::string	PresidentialPardonForm::getTarget(void) const
{
	return (target);
}

void	PresidentialPardonForm::beSigned(const Bureaucrat &other)
{
	if (other.getGrade() <= this->getGradeToSign())
	{
		std::cout << ORANGE << other.getName() << "(boreaucrat): has signed " << this->getName() << RESET << std::endl;
		this->setSign(true);
		return ;
	}
	std::cout << ORANGE << other.getName() << "(boreaucrat): has no grade to sign " << this->getName() << RESET << std::endl;
}
void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() <= this->getGradeToExec())
	{
		std::cout << ORANGE << executor.getName() << "(boreaucrat): ";
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox.\n" RESET;
		return ;
	}
	std::cout << ORANGE << executor.getName() << "(bureaucrat): has no grade enough to execute\n" RESET;
}