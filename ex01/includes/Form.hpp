#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class	Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExec; 
	public:
		Form(const std::string &name, int toSign, int toExec);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		//	Getters
		std::string	getName(void) const;
		bool		getIsSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExec(void) const;

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
		void	beSigned(const Bureaucrat &other);
};

std::ostream &operator<<(std::ostream &out, const Form &other);

#endif
