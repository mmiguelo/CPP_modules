#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

//colors
#define R		"\033[0;31m" //RED
#define G		"\033[0;32m" //GREEN
#define Y		"\033[0;33m" //YELLOW
#define B		"\033[0;34m" //BLUE
#define RST		"\033[0m"   //RESET

class Form
{
	private:
		const std::string 	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_executeGrade;

	public:
		Form();
		Form(const std::string &name, int signGrade, int executeGrade);
		Form(const Form &other);
		Form& operator=(const Form &other);
		~Form();

		const std::string 	&getName() const;
		int 				getSignGrade() const;
		int 				getExecuteGrade() const;
		bool				getSigned() const;
		void				setSigned(bool sign);
		void				beSigned(const class Bureaucrat &b);

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

std::ostream &operator<<(std::ostream &out, const Form &form);