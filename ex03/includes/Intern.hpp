#ifndef INTERN_HPP
#define INTERN_HPP

# define BRIGHT_RED "\033[1;31m"
# define BRIGHT_BLUE "\033[1;34m"
# define ORANGE "\033[38;5;208m"
# define BRIGHT_GREEN "\033[1;32m"
# define RESET "\033[0m"

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyResquestForm.hpp"

class Intern
{
	private:
		AForm	*president(const std::string &target);
		AForm	*robot(const std::string &target);
		AForm	*shrubbery(const std::string &target);
		typedef struct s_formMap
		{
			std::string	name;
			AForm	*(Intern::*f)(const std::string &target);
		}	t_formMap;
	public:
		Intern();
		Intern(const Intern &other);
		Intern	&operator=(const Intern &other);
		~Intern();

		//	Methods
		AForm	*makeForm(const std::string &formName, const std::string &target);
};

std::ostream	&operator<<(std::ostream &out, const Intern &other);

#endif