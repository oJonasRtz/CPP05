#ifndef CLASSTEMPLATE_HPP
#define CLASSTEMPLATE_HPP

# define BRIGHT_RED "\033[1;31m"
# define BRIGHT_BLUE "\033[1;34m"
# define ORANGE "\033[38;5;208m"
# define BRIGHT_GREEN "\033[1;32m"
# define RESET "\033[0m"

#include <iostream>

class ClassTemplate
{
	private:
		/* data */
	public:
		ClassTemplate();
		ClassTemplate(const ClassTemplate &other);
		ClassTemplate	&operator=(const ClassTemplate &other);
		~ClassTemplate();
};

std::ostream	&operator<<(std::ostream &out, const ClassTemplate &other);

#endif