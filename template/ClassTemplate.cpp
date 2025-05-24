#include "ClassTemplate.hpp"

ClassTemplate::ClassTemplate()
{
	std::cout << BRIGHT_GREEN "constructor called\n" RESET;
}
ClassTemplate::ClassTemplate(const ClassTemplate &other)
{
	std::cout << BRIGHT_GREEN "copy constructor called\n" RESET;
	*this = other;
}
ClassTemplate&	ClassTemplate::operator=(const ClassTemplate &other)
{
	std::cout << BRIGHT_GREEN "assignment operator\n" RESET;
	if (this != &other)
		/*	copy	*/
	return (*this);
}
ClassTemplate::~ClassTemplate()
{
	std::cout << BRIGHT_RED "destructor called\n" RESET;
}

std::ostream	&operator<<(std::ostream &out, const ClassTemplate &other)
{
	(void)other;
	out << "temp";
	return (out);
}