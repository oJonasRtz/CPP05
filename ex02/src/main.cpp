#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyResquestForm.hpp"

static void	canonicalTests(void)
{
	std::cout << ORANGE << std::string(40, '-') << "\n" << "\tCanonical Ortodox tests\n" << std::string(40, '-') << RESET << std::endl;
	std::cout << "\t\tConstructors\n" << std::string(40, '-') << std::endl;
	Bureaucrat	*a = new Bureaucrat("Bob", 50);
	Bureaucrat	*b = new Bureaucrat(*a);
	Bureaucrat	*c = new Bureaucrat("Will", 40);

	std::cout << "\n\t\tOperator <<\n" << std::string(40, '-') << std::endl;
	std::cout << *a << "\n" << *b << "\n" << *c << std::endl;

	std::cout << "\n\t\tAssignment test =\n" << std::string(40, '-') << std::endl;
	*c = *a;
	std::cout << *c << std::endl;

	std::cout << "\n\t\tDestructors\n" << std::string(40, '-') << std::endl;
	delete a;
	delete b;
	delete c;
}

static void	tryIncrement(Bureaucrat &a, int n)
{
	try
	{
		a.incrementGrade(n);
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception found\n";
	}
}

static void	tryDecrement(Bureaucrat &a, unsigned int n)
{
	try
	{
		a.decrementGrade(n);
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception found\n";
	}
}

static void	gradeTests(void)
{
	std::cout << ORANGE << std::string(40, '-') << "\n" << "\tGrade tests\n" << std::string(40, '-') << RESET << std::endl;
	Bureaucrat *a = new Bureaucrat("Bob", 50);
	std::cout << std::string(40, '-') << "\n" << "\tStats\n" << std::string(40, '-') << std::endl;
	std::cout << ORANGE << *a << RESET << std::endl;

	std::cout << std::string(40, '-') << "\n" << "\tNomal\n" << std::string(40, '-') << std::endl;
	tryIncrement(*a, 5);
	tryDecrement(*a, 10);

	std::cout << std::string(40, '-') << "\n" << "\tOver-increment\n" << std::string(40, '-') << std::endl;
	tryIncrement(*a, 500);

	std::cout << std::string(40, '-') << "\n" << "\tOver-decrement\n" << std::string(40, '-') << std::endl;
	tryDecrement(*a, 500);

	std::cout << std::string(40, '-') << "\n" << "\tFinal-stats\n" << std::string(40, '-') << std::endl;
	std::cout << ORANGE << *a << "\n" RESET << std::endl;
	
	std::cout << std::string(40, '-') << "\n" << "\tGrade set tests >150 and <0\n" << std::string(40, '-') << std::endl;
	try
	{
		Bureaucrat	*b = new Bureaucrat("B", -6);
		std::cout  << *b << "\n" << "\n" << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception found\n";
	}
	delete a;
}

static int	errorOut(void)
{
	std::cout << BRIGHT_RED "Correct input: ./form <1 or 2 or 3>\n" RESET;
	return (0);
}

static void	shrubberyTest(void)
{
	std::cout << ORANGE << std::string(40, '-') << "\n" << "\tShrubbery tests\n" << std::string(40, '-') << RESET << std::endl;

	std::cout << std::string(40, '-') << "\n" << "\tConstructors\n" << std::string(40, '-') << std::endl;
	ShrubberyCreationForm	*a = new ShrubberyCreationForm("test");
	ShrubberyCreationForm	*e = new ShrubberyCreationForm(*a);
	ShrubberyCreationForm	*d = new ShrubberyCreationForm("adas");
	std::cout << *a << "\n" << *d << "\n" << *e << std::endl;
	*d = *a;
	std::cout << *d << std::endl;
	
	std::cout << std::string(40, '-') << "\n" << "\tOperator <<\n" << std::string(40, '-') << std::endl;
	std::cout << *a << '\n' << *d << std::endl;

	std::cout << std::string(40, '-') << "\n" << "\tExecute\n" << std::string(40, '-') << std::endl;
	Bureaucrat				*b = new Bureaucrat("B", 150);
	Bureaucrat				*c = new Bureaucrat("C", 1);

	a->execute(*b);
	a->execute(*c);

	std::cout << std::string(40, '-') << "\n" << "\tSign\n" << std::string(40, '-') << std::endl;
	b->signForm(*a);
	std::cout << *a << std::endl;
	c->signForm(*a);
	std::cout << *a << std::endl;

	delete c;
	delete b;

	std::cout << std::string(40, '-') << "\n" << "\tdestructors\n" << std::string(40, '-') << std::endl;
	delete a;
	delete d;
	delete e;
}

static void	robotTest(void)
{
	std::cout << ORANGE << std::string(40, '-') << "\n" << "\tRobot tests\n" << std::string(40, '-') << RESET << std::endl;

	std::cout << std::string(40, '-') << "\n" << "\tConstructors\n" << std::string(40, '-') << std::endl;
	RobotomyResquestForm	*a = new RobotomyResquestForm("test");
	RobotomyResquestForm	*e = new RobotomyResquestForm(*a);
	RobotomyResquestForm	*d = new RobotomyResquestForm("adas");
	std::cout << *a << "\n" << *d << "\n" << *e << std::endl;
	*d = *a;
	std::cout << *d << std::endl;
	
	std::cout << std::string(40, '-') << "\n" << "\tOperator <<\n" << std::string(40, '-') << std::endl;
	std::cout << *a << '\n' << *d << std::endl;

	std::cout << std::string(40, '-') << "\n" << "\tExecute\n" << std::string(40, '-') << std::endl;
	Bureaucrat				*b = new Bureaucrat("B", 150);
	Bureaucrat				*c = new Bureaucrat("C", 1);

	for (int i = 0; i < 10; i++)
		a->execute(*c);

	std::cout << std::string(40, '-') << "\n" << "\tSign\n" << std::string(40, '-') << std::endl;
	b->signForm(*a);
	std::cout << *a << std::endl;
	c->signForm(*a);
	std::cout << *a << std::endl;

	delete c;
	delete b;

	std::cout << std::string(40, '-') << "\n" << "\tdestructors\n" << std::string(40, '-') << std::endl;
	delete a;
	delete d;
	delete e;
}

int	main(int argc, char **argv)
{
	if (argc == 1 || argc > 2)
		return (errorOut());

	const int	len = 4;
	std::string	arg;
	static const t_select	select[len] =
	{
		{"1", &canonicalTests},
		{"2", &gradeTests},
		{"3", &shrubberyTest},
		{"4", &robotTest}
	};
	arg = argv[1];
	for (int i = 0; i < len; i++)
		if (select[i].str == arg)
			select[i].f();
	return (0);
}
