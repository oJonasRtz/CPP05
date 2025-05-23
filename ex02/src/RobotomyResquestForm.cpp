#include "RobotomyResquestForm.hpp"

RobotomyResquestForm::RobotomyResquestForm(const std::string &target) : AForm(target, 72, 45), target(target)
{
	std::cout << BRIGHT_GREEN "(Robot)constructor called\n" RESET;
}
RobotomyResquestForm::RobotomyResquestForm(const RobotomyResquestForm &other): AForm(other.getTarget(), 72, 45), target(other.getTarget())
{
	std::cout << BRIGHT_GREEN "(Robot)copy constructor called\n" RESET;
}
RobotomyResquestForm& RobotomyResquestForm::operator=(const RobotomyResquestForm &other)
{
	std::cout << BRIGHT_GREEN "(Robot)assignment operator\n" RESET;
	if (this != &other)
		this->target = other.getTarget();
	return (*this);
}
RobotomyResquestForm::~RobotomyResquestForm()
{
	std::cout << BRIGHT_RED "(Robot)destructor called\n" RESET;
}

std::string RobotomyResquestForm::getTarget(void) const
{
	return (target);
}

//	Methods
void	RobotomyResquestForm::beSigned(const Bureaucrat &other)
{
	if (other.getGrade() <= this->getGradeToSign())
		this->beSigned(other);
}
void	RobotomyResquestForm::execute(Bureaucrat const &executor) const
{
	(void)executor;
}

std::ostream	&operator<<(std::ostream &out, const RobotomyResquestForm &other)
{
	out << "(Robot)target: " << other.getTarget();
	return (out);
}
