#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyResquestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

template <typename T>
static void	caninical(T &original)
{
	std::cout << ORANGE << std::string(40, '-') << "\n" << "\tCanonical Ortodox tests\n" << std::string(40, '-') << RESET << std::endl;
	std::cout << "\t\tConstructors\n" << std::string(40, '-') << std::endl;
	T	*a	= new T(original);
	T	*b	= new T("Canonical");

	std::cout << "\n\t\tOperator <<\n" << std::string(40, '-') << std::endl;
	std::cout << original << "\n" << *a << "\n" << *b << "\n";

	std::cout << "\n\t\tAssignment test =\n" << std::string(40, '-') << std::endl;
	*a = *b;
	std::cout << *a << "\n" << *b << "\n";

	std::cout << std::string(40, '-') << "\n" << "\tExecute\n" << std::string(40, '-') << std::endl;
	Bureaucrat	*c = new Bureaucrat("C", 1);
	Bureaucrat	*d = new Bureaucrat("D", 150);
	a->execute(*c);
	a->execute(*d);

	std::cout << std::string(40, '-') << "\n" << "\tSign\n" << std::string(40, '-') << std::endl;
	d->signForm(*a);
	std::cout << *a << "\n";
	c->signForm(*a);
	std::cout << *a << "\n";

	delete c;
	delete d;

	std::cout << "\n\t\tDestructors\n" << std::string(40, '-') << std::endl;
	delete a;
	delete b;
}

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

	ShrubberyCreationForm	*a = new ShrubberyCreationForm("test");
	caninical(*a);
	delete a;
}

static void	robotTest(void)
{
	std::cout << ORANGE << std::string(40, '-') << "\n" << "\tRobot tests\n" << std::string(40, '-') << RESET << std::endl;

	RobotomyResquestForm	*a = new RobotomyResquestForm("test");
	caninical(*a);

	std::cout << "\n\tMore execution tests\n" << std::string(40, '-') << std::endl;
	Bureaucrat	*b = new Bureaucrat("B", 1);
	for (int i = 0; i < 10; i++)
		a->execute(*b);
	
	delete a;
	delete b;
}

static void	presidentTest(void)
{
	PresidentialPardonForm	*a = new PresidentialPardonForm("test");

	std::cout << ORANGE << std::string(40, '-') << "\n" << "\tPresident tests\n" << std::string(40, '-') << RESET << std::endl;
	caninical(*a);
	delete a;
}

static void	execTest(void)
{
	std::cout << ORANGE << std::string(40, '-') << "\n" << "\tBoreaucrat execute tests\n" << std::string(40, '-') << RESET << std::endl;
	Bureaucrat	*a = new Bureaucrat("A", 150);
	AForm	*b = new PresidentialPardonForm("test");
	Bureaucrat	*c = new Bureaucrat("C", 1);

	a->executeForm(*b);
	c->executeForm(*b);

	c->signForm(*b);

	a->executeForm(*b);
	c->executeForm(*b);

	delete a;
	delete b;
	delete c;
}

static void	internTest(void)
{
	std::cout << ORANGE << std::string(40, '-') << "\n" << "\tIntern tests\n" << std::string(40, '-') << RESET << std::endl;
	std::cout << "\t\tConstructors\n" << std::string(40, '-') << std::endl;
	Intern	*a = new Intern();
	Intern	*b = new Intern(*a);

	std::cout << "\n\t\tOperator <<\n" << std::string(40, '-') << std::endl;
	std::cout << *a << "\n" << *b << "\n";

	std::cout << "\n\t\tAssignment test =\n" << std::string(40, '-') << std::endl;
	*a = *b;
	std::cout << *a << "\n" << *b << "\n";

	std::cout << std::string(40, '-') << "\n" << "\tCreate forms\n" << std::string(40, '-') << std::endl;
	AForm	*x = a->makeForm("robotomy request", "test");
	AForm	*y = a->makeForm("presidential request", "test");
	AForm	*z = a->makeForm("shrubbery request", "test");
	AForm	*error = a->makeForm("sdfdsf", "test");

	delete x;
	delete y;
	delete z;
	delete error;

	std::cout << "\n\t\tDestructors\n" << std::string(40, '-') << std::endl;
	delete a;
	delete b;
}

int	main(int argc, char **argv)
{
	if (argc == 1 || argc > 2)
		return (errorOut());

	const int	len = 7;
	std::string	arg;
	static const t_select	select[len] =
	{
		{"1", &canonicalTests},
		{"2", &gradeTests},
		{"3", &shrubberyTest},
		{"4", &robotTest},
		{"5", &presidentTest},
		{"6", &execTest},
		{"7", &internTest}
	};
	arg = argv[1];
	for (int i = 0; i < len; i++)
		if (select[i].str == arg)
			select[i].f();
	return (0);
}
