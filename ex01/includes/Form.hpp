#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExec; 
	public:
		Form(const std::string &name, bool isSigned, int toSign, int toExec);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		//	Getters
		std::string	getName(void) const;
		bool		getIsSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExec(void) const;
};

std::ostream &operator<<(std::ostream &out, const Form &other);

#endif
