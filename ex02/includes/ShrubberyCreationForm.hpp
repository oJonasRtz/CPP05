#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string	target;
	public:
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		virtual ~ShrubberyCreationForm();

		//	Getters
		std::string	getTarget(void) const;

		//	Methods
		virtual void	beSigned(const Bureaucrat &other);
		virtual void	execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &other);

#endif