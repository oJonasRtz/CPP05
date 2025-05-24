#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include "AForm.hpp"

class RobotomyResquestForm : public AForm
{
	private:
		std::string	target;
	public:
		RobotomyResquestForm(const std::string &target);
		RobotomyResquestForm(const RobotomyResquestForm &other);
		RobotomyResquestForm &operator=(const RobotomyResquestForm &other);
		virtual ~RobotomyResquestForm();

		//	Getters
		std::string	getTarget(void) const;

		//	Methods
		virtual void	beSigned(const Bureaucrat &other);
		virtual void	execute(Bureaucrat const &executor) const;
};

std::ostream	&operator<<(std::ostream &out, const RobotomyResquestForm &other);

#endif