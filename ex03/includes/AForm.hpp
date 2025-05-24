#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class	Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExec; 
	public:
		AForm(const std::string &name, int toSign, int toExec);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		//	Getters
		std::string	getName(void) const;
		bool		getIsSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExec(void) const;

		//	Setters
		void	setSign(const bool &sign);

		//	Exception
		class	GradeTooHighExcept: public std::exception
		{
			public:
				virtual const  char	*what(void) const throw()
				{
					return ("Grade too high.");
				}
		};
		class	GradeTooLowExcept: public std::exception
		{
			public:
				virtual const char	*what(void) const throw()
				{
					return ("Grade too low.");
				}
		};

		//	Methods
		virtual void	beSigned(const Bureaucrat &other) = 0;
		virtual void	execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &other);

#include "Bureaucrat.hpp"

#endif
