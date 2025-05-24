#include "Intern.hpp"

Intern::Intern()
{
	std::cout << BRIGHT_GREEN "Intern: constructor called\n" RESET;
}
Intern::Intern(const Intern &other)
{
	std::cout << BRIGHT_GREEN "Intern: copy constructor called\n" RESET;
	*this = other;
}
Intern&	Intern::operator=(const Intern &other)
{
	(void)other;;
	std::cout << BRIGHT_GREEN "Intern: assignment operator\n" RESET;
	return (*this);
}
Intern::~Intern()
{
	std::cout << BRIGHT_RED "Intern: destructor called\n" RESET;
}

std::ostream	&operator<<(std::ostream &out, const Intern &other)
{
	(void)other;
	out << "Intern";
	return (out);
}

AForm*	Intern::president(const std::string &target)
{
	AForm	*a = new PresidentialPardonForm(target);

	return (a);
}
AForm*	Intern::robot(const std::string &target)
{
	AForm	*a = new RobotomyResquestForm(target);

	return (a);
}
AForm*	Intern::shrubbery(const std::string &target)
{
	AForm	*a = new ShrubberyCreationForm(target);

	return (a);
}

AForm*	Intern::makeForm(const std::string &formName, const std::string &target)
{
	int		flag = 1;
	AForm	*a = NULL;
	t_formMap	map[3] =
	{
		{"shrubbery request", &Intern::shrubbery},
		{"presidential request", &Intern::president},
		{"robotomy request", &Intern::robot}
	};

	for (int i = 0; i < 3; i++)
		if (map[i].name == formName)
		{
			std::cout << ORANGE "Intern: creates " << formName << "\n" RESET;
			a = (this->*map[i].f)(target);
			flag = 0;
			break;
		}
	if (flag)
		std::cout << ORANGE "Intern: Couldn't create " << formName << "\n" RESET;

	return (a);
}
