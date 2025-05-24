#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

# define BRIGHT_RED "\033[1;31m"
# define BRIGHT_BLUE "\033[1;34m"
# define ORANGE "\033[38;5;208m"
# define BRIGHT_GREEN "\033[1;32m"
# define RESET "\033[0m"

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	target;
	public:
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &other);
		virtual ~PresidentialPardonForm();

		//	Getters
		std::string	getTarget(void) const;

		//	Methods
		virtual void	beSigned(const Bureaucrat &other);
		virtual void	execute(Bureaucrat const &executor) const;
};

std::ostream	&operator<<(std::ostream &out, const PresidentialPardonForm &other);

#endif