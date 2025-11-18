#pragma once
#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

//colors
#define R		"\033[0;31m" //RED
#define G		"\033[0;32m" //GREEN
#define Y		"\033[0;33m" //YELLOW
#define B		"\033[0;34m" //BLUE
#define RST		"\033[0m"   //RESET

class Form;

class Bureaucrat
{
	private:
		const std::string 	_name;
		int 				_grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		const std::string 	&getName() const;
		int 				getGrade() const;
		void 				incrementGrade();
		void 				decrementGrade();
		void				signForm(Form &form);

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

std::ostream& operator << (std::ostream& output, const Bureaucrat& b);