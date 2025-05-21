#include "Bureaucrat.hpp"

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

	delete a;
}

int	main(void)
{
	canonicalTests();
	gradeTests();
	return (0);
}
