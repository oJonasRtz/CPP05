#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grad) : name(name)
{
	if (grad > 150)
		throw (GradeTooLowException());
	else if (grad <= 0)
		throw (GradeTooHighException());
	this->grade = grad;
	std::cout << BRIGHT_GREEN << this->getName() << "(Bureaucrat): constructor called\n" RESET;
}
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.getName()), grade(other.getGrade())
{
	(void)other;
	std::cout << BRIGHT_GREEN << this->getName() << "(Bureaucrat): copy constructor called\n" RESET;
}
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << BRIGHT_GREEN << this->getName() << "(Bureaucrat): assignment operator\n" RESET;
	if (this != &other)
		this->grade = other.getGrade();
	return (*this);
}
Bureaucrat::~Bureaucrat()
{
	std::cout << BRIGHT_RED << this->getName() << "(Bureaucrat): destructor called\n" RESET;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &other)
{
	out << other.getName() << ", bureaucrat grade " << other.getGrade();
	return (out);
}

int			Bureaucrat::getGrade(void) const
{
	return (grade);
}
const std::string&	Bureaucrat::getName(void) const
{
	return (name);
}

void	Bureaucrat::incrementGrade(unsigned int amount)
{
	if (grade - (int)amount < 1)
		throw GradeTooHighException();
	grade -= amount;
	std::cout << ORANGE << this->getName() << "(Bureaucrat): incremented to " << grade << RESET << std::endl;
}
void	Bureaucrat::decrementGrade(unsigned int amount)
{
	if (grade + (int)amount > 150)
		throw (GradeTooLowException());
	grade += amount;
	std::cout << ORANGE << this->getName() << "(Bureaucrat): decremented to " << grade << RESET << std::endl;
}
void	Bureaucrat::signForm(AForm &other)
{
	other.beSigned(*this);
}
