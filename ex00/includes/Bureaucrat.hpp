#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# define BRIGHT_RED "\033[1;31m"
# define BRIGHT_BLUE "\033[1;34m"
# define ORANGE "\033[38;5;208m"
# define BRIGHT_GREEN "\033[1;32m"
# define RESET "\033[0m"

#include <iostream>
#include <string>

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat(const std::string &name, int grad);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat	&operator=(const Bureaucrat &other);
		~Bureaucrat();

		//	Methods
		void	incrementGrade(unsigned int amount);
		void	decrementGrade(unsigned int amount);

		//	Getters
		int					getGrade(void) const;
		const std::string	&getName(void) const;

		//	Classes
		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw()
				{
					return (ORANGE "Grade too high." RESET);
				}

		};
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw()
				{
					return (ORANGE "Grade too low." RESET);
				}
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &other);

typedef struct s_select
{
	std::string str;
	void	(*f)(void);
}	t_select;

#endif