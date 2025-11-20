#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

//colors
#define RED   "\033[0;31m"
#define GRN   "\033[0;32m"
#define YEL   "\033[0;33m"
#define BLU   "\033[0;34m"
#define CYA   "\033[0;36m"
#define BMAG  "\033[35;1m"
#define BYEL  "\033[33;1m"
#define RST   "\033[0m"

class AForm
{
	private:
		const std::string 	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_executeGrade;

	public:
		AForm();
		AForm(const std::string &name, int signGrade, int executeGrade);
		AForm(const AForm &other);
		AForm& operator=(const AForm &other);
		virtual ~AForm();

		const std::string 	&getName() const;
		int 				getSignGrade() const;
		int 				getExecuteGrade() const;
		bool				getSigned() const;
		void				setSigned(bool sign);
		void				beSigned(const class Bureaucrat &b);

		virtual void execute(Bureaucrat const &executor) const = 0;
		class AlreadySignedException: public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Form is already signed!";
				}
		};

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Grade chosen is too high!";
				}
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Grade chosen is too low!";
				}
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &form);