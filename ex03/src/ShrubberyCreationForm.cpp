#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm(target, 145, 137), target(target)
{
	std::cout << BRIGHT_GREEN "ShrubberyCreationForm: constructor called\n" RESET;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other.getTarget(), 145, 137), target(other.getTarget())
{
	std::cout << BRIGHT_GREEN "ShrubberyCreationForm: copy constructor called\n" RESET;
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << BRIGHT_GREEN "ShrubberyCreationForm: assignment operator\n" RESET;
	if (this != &other)
		this->target = other.getTarget();
	return (*this);
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << BRIGHT_RED "ShrubberyCreationForm: destructor called\n" RESET;
}

//	Getters
std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (target);
}

//	Methods
void	ShrubberyCreationForm::beSigned(const Bureaucrat &other)
{
	if (other.getGrade() <= this->getGradeToSign())
	{
		std::cout << ORANGE << other.getName() << "(boreaucrat): has signed " << this->getName() << RESET << std::endl;
		this->setSign(true);
		return ;
	}
	std::cout << ORANGE << other.getName() << "(boreaucrat): has no grade to sign " << this->getName() << RESET << std::endl;
}
void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeToExec())
	{
		std::cout << ORANGE << executor.getName() << "(bureaucrat): has no grade enough to execute\n" RESET;
		return ;
	}
	std::ofstream	outfile;
	std::string		filename = this->getTarget() + "_shrubbery"; 
	outfile.open(filename.c_str());
	if (!outfile.is_open())
	{
		std::cout << BRIGHT_RED "Shrubbery: Error trying to open the outfile\n" RESET;
		return ;
	}
	outfile <<
		"   ^\n" << 
		"  ^^^\n" <<
		" ^^^^^\n" <<
		"^^^^^^^\n" <<
		"  |||\n" <<
		"  |||\n";
	outfile.close();
	std::cout << ORANGE << executor.getName() << "(bureaucrat): Shrubbery created at " << filename << "\n"  RESET;
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &other)
{
	out << 
		"(Shrubbery)target: " << other.getTarget() <<
		"; Grade to sign: " << other.getGradeToSign() <<
		"; Grade to execute: " << other.getGradeToExec() <<
		"; Is signed: " << (other.getIsSigned() ? "yes" : "no");
	return (out);
}
