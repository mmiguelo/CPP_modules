#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <ctime>
#include "AForm.hpp"

//colors
#define RED   "\033[0;31m"
#define GRN   "\033[0;32m"
#define YEL   "\033[0;33m"
#define BLU   "\033[0;34m"
#define CYA   "\033[0;36m"
#define BMAG  "\033[35;1m"
#define BYEL  "\033[33;1m"
#define RST   "\033[0m"

class AForm;

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
		void				signForm(AForm &form);
		void				executeForm(const AForm &form) const;

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